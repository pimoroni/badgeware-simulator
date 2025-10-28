import socket

# an asynchronous http client heavily inspired by requests
#
# call `fetch` to add a new http client to the fetching pool, regularly call
# `tick` to allow the pool to process their requests a little further.
#
# if a file handle is provided then the result will be streamed into the file
# otherwise it will be passed into the callback upon completion

_fetchers = []

class Fetcher():
  GET_ADDR_INFO = 0
  CONNECT = 1
  SEND_HEADERS = 2
  SEND_BODY = 3
  READ_HEADERS = 4
  READ_BODY = 5

  def __init__(self, method, url, data=None, json=None, headers=None, auth=None, timeout=0, file=None):
    self._state = Fetcher.CONNECT

    self._headers = headers.copy() if headers else {}
    self._data = data
    self._file = file
    self._status = None
    self._buffer = bytes()

    if auth is not None:
      import binascii
      formatted = b"{}:{}".format(auth[0], auth[1])
      formatted = str(binascii.b2a_base64(formatted)[:-1], "ascii")
      self._headers["Authorization"] = "Basic {}".format(formatted)

    self._path = ""
    try:
      self._protocol, _, self._host, self._path = url.split("/", 3)
    except ValueError:
      self._protocol, _, self._host = url.split("/", 2)

    # determine default port for http or https requests
    if self._protocol == "http:":
      self._port = 80
    elif self._protocol == "https:":
      import tls
      self._port = 443
    else:
      raise ValueError(f"Unsupported protocol: {self._protocol}")

    # if supplied body is to be json encoded then do that now
    if json is not None:
      assert self._data is None
      from json import dumps
      self._data = dumps(json)
      if "Content-Type" not in headers:
        headers["Content-Type"] = "application/json"

    # if port specified, then separate it from the host value
    if ":" in host:
      self._host, self._port = self._host.split(":", 1)
      self._port = int(self._port)

    if "Host" not in self._headers:
      self._headers["Host"] = self._host

    if "Connection" not in self._headers:
      self._headers["Connection"] = "close"

    if self._data:
      headers["Content-Length"] = str(len(self._data))

  def tick(self):
    #self._buffer += self._request.raw.read()

    if self._state == Fetcher.GET_ADDR_INFO:

      # get server ip address
      self._addrinfo = socket.getaddrinfo(self._host, self._port, 0, socket.SOCK_STREAM)
      self._addrinfo = self._addrinfo[0]
      self._state = Fetcher.CONNECT

    elif self._state == Fetcher.CONNECT:

      # create connection
      self._socket = socket.socket(self._addrinfo[0], socket.SOCK_STREAM, self._addrinfo[2])

      if timeout is not None:
        self._socket.settimeout(timeout)
      self._socket.connect(self._addrinfo[-1])
      if self._protocol == "https:":
        context = tls.SSLContext(tls.PROTOCOL_TLS_CLIENT)
        context.verify_mode = tls.CERT_NONE
        self._socket = context.wrap_socket(self._socket, server_hostname=self._host)
      self._socket.write(b"%s /%s HTTP/1.0\r\n" % (self._method, self._path))
      self._state = Fetcher.SEND_HEADERS

    elif self._state == Fetcher.SEND_HEADERS:

      for k in self._headers:
        self._socket.write(k)
        self._socket.write(b": ")
        self._socket.write(self._headers[k])
        self._socket.write(b"\r\n")
      self._socket.write(b"\r\n")
      self._state = Fetcher.SEND_BODY

    elif self._state == Fetcher.SEND_BODY:

      # send the request body
      if self._data:
        self._socket.write(self._data)
      self._state = Fetcher.READ_STATUS
      self._data = bytes()

    elif self._state == Fetcher.READ_STATUS:

      l = self._socket.readline()
      l = l.split(None, 2)
      if len(l) < 2:
        raise ValueError(f"HTTP error: BadStatusLine:\n{l}")
      self._status = int(l[1])
      self._state = Fetcher.READ_HEADERS

    elif self._state == Fetcher.READ_HEADERS:

      self._headers = {}
      while True:
        l = self._socket.readline()
        if not l or l == b"\r\n":
          break

        key, value = str(l, "utf-8").split(":", 1)
        self._headers[key] = value.strip()

      # check for redirection
      if "Location" in self._headers:
        self._socket.close()

        # todo: do we restart this fetcher, or create a new one?
        print(f"! http redirect to {self._headers["Location"]}")

      # check for unsupported features
      if "Transfer-Encoding" in self._headers:
        if "chunked" in self._headers["Transfer-Encoding"]:
          raise ValueError(f"Unsupported {str(l, "utf-8")}")

      self._state = Fetcher.READ_BODY

    elif self._state == Fetcher.READ_BODY:

      try:
        chunk = self._socket.recv(4096)
        if chunk:
          if self._file:
            self._file.write(chunk)
          else:
            self._data += chunk
      except OSError as e:
        # socket recv is
        print(e)
        self._callback(self._status, self._headers, self._data)

      self._state = Fetcher.DONE



def fetch(method, url, data=None, headers=None, auth=None, timeout=None, file=None):
  fetcher = Fetcher(method, url, data, json, headers, auth, timeout, file)
  fetcher.append(fetcher)

# give active fetchers a chance to process their work
def tick():
  for fetcher in _fetchers:
    fetcher.tick()