import socket
import binascii
import tls
import json
import time

# TODO: is it performant to run multiple fetches alongside each other or is it
# better to run them one after another as a queue?

# an asynchronous http client heavily inspired by requests
#
# call `fetch` to add a new http client to the fetching pool, regularly call
# `tick` to allow the pool to process their requests a little further.
#
# if a file handle is provided then the result will be streamed into the file
# otherwise it will be passed into the callback upon completion

_fetchers = []

class FetchResponse():
  def __init__(self):
    self.ok = None
    self.status = None
    self.headers = None
    self.body = None

class Fetcher():
  def __init__(self, method, url, body=None, headers=None, auth=None, timeout=0, file=None, callback=None):
    self._method = method
    self._headers = headers.copy() if headers else {}
    self._callback = callback
    self._body = body # request body
    self._file = file # optional file pointer to store response body (or is returned as bytes in response)

    self._state = None
    self._response = FetchResponse()
    self._buffer = bytes()

    try:
      # add auth headers if needed
      if auth is not None:
        if len(auth) != 2:
          raise ValueError("`auth` must be a tuple or list containing username and password")

        formatted = b"{}:{}".format(auth[0], auth[1])
        formatted = str(binascii.b2a_base64(formatted)[:-1], "ascii")
        self._headers["Authorization"] = "Basic {}".format(formatted)

      # split the supplied url into its component parts
      try:
        self._protocol, _, self._host, self._path = url.split("/", 3)
      except ValueError:
        self._path = ""
        self._protocol, _, self._host = url.split("/", 2)
      self._protocol = self._protocol[:-1]
      if self._protocol not in ["http", "https"]:
        raise ValueError(f"unsupported protocol '{self._protocol}', only http or https supported")

      # if port specified, then separate it from the host value, or use defaults
      if ":" in self._host:
        self._host, self._port = self._host.split(":", 1)
        if not self._post.isdigit():
          raise ValueError(f"port must be a number, you supplied '{self._port}'")
        self._port = int(self._port)
      else:
        self._port = 80 if self._protocol == "http" else 443

      # if method is GET and we have been supplied a body then build the query string
      if self._method == "get" and body:
        if not isinstance(body, dict):
          raise ValueError("`body` must be a dictionary containing query string key-value pairs")

        # TODO: build query string

      if self._method == "post" or self._method == "put":
        # if supplied body is not a string or bytes then json encode it first
        if not isinstance(self._body, str) and not isinstance(self._body, bytes):
          try:
            self._body = json.dumps(self._body)
            self._headers["Content-Type"] = "application/json"
          except:
            raise ValueError("could not encode supplied `body` as json")

      # add useful extra headers
      if "Host" not in self._headers:
        self._headers["Host"] = self._host
      if "Connection" not in self._headers:
        self._headers["Connection"] = "close"
      if self._body:
        self._headers["Content-Length"] = str(len(self._body))

      # convert headers and body ready for sending
      self._buffer = b"%s /%s HTTP/1.0\r\n" % (self._method, self._path)
      for key, value in self._headers.items():
        self._buffer += b"%s: %s\r\n" % (key, value)
      self._buffer += b"\r\n"
      if body:
        self._buffer += bytes(body, "utf-8")

      # we're done with the headers and body now, free up the memory
      self._headers = None
      self._body = None

      # get server details
      self._addrinfo = socket.getaddrinfo(self._host, self._port, 0, socket.SOCK_STREAM)
      self._addrinfo = self._addrinfo[0]

      # create the socket
      self._socket = socket.socket(self._addrinfo[0], socket.SOCK_STREAM, self._addrinfo[2])
      self._socket.settimeout(timeout)

      # establish the connection
      self._socket.connect(self._addrinfo[-1])
      if self._protocol == "https":
        context = tls.SSLContext(tls.PROTOCOL_TLS_CLIENT)
        context.verify_mode = tls.CERT_NONE
        self._socket = context.wrap_socket(self._socket, server_hostname=self._host)
    except:
      self.failed()
      raise # re-raise the exception for user to handle

  def tick(self):
    class State():
      SENDING = 1
      READ_STATUS = 2
      READ_HEADERS = 3
      READ_BODY = 4
      DONE = 6

    try:
      # setup initial state
      if self._state is None:
        self._state = State.SENDING
        self._buffer_sent = 0

      # transmit the request headers and body
      if self._state == State.SENDING:
        mv = memoryview(self._buffer)
        remaining = len(self._buffer) - self._buffer_sent
        chunk = 4096 if remaining > 4096 else remaining
        remaining -= self._socket.send(mv[self._buffer_sent:self._buffer_sent + chunk])
        if remaining == 0:
          self._buffer = None # clear buffer to free memory
          self._state = State.READ_STATUS

      elif self._state == State.READ_STATUS:
        line = self._socket.readline()
        try:
          _, status, _ = line.split()
          self._response.status = int(status)
          self._state = State.READ_HEADERS
        except:
          self.failed(f"fetch error: bad http status line returned '{line}'")

      elif self._state == State.READ_HEADERS:

        self._response.headers = {}
        while True:
          line = self._socket.readline()
          if not line or line == b"\r\n":
            break

          key, value = str(line, "utf-8").split(":", 1)
          self._response.headers[key] = value.strip()

        # check for redirection
        if "Location" in self._response.headers:
          self._socket.close()
          # todo: do we restart this fetcher, or create a new one? currently redirect not supported
          self.failed("usupported redirect requested by server response")

        # check for unsupported features
        if "Transfer-Encoding" in self._response.headers:
          if "chunked" in self._response.headers["Transfer-Encoding"]:
            self.failed(f"unsupported Transfer-Encoding: '{self._response.headers["Transfer-Encoding"]}'")

        self._state = State.READ_BODY

      elif self._state == State.READ_BODY:
        self._response.body = b""
        try:
          chunk = self._socket.recv(4096)
          if chunk:
            if self._file:
              self._file.write(chunk)
            else:
              self._response.body += chunk
          else:
            if self._file:
              self._file.close()

            if 200 <= self._response.status < 300:
              self.complete()
            else:
              self.failed(f"server returned error http status code {self._response.status}")
        except OSError as e:
          self.failed()
    except Exception as e:
      self.failed(str(e))

  def complete(self):
    self._response.ok = True
    self._callback(self._response)
    _fetchers.remove(self)

  def failed(self, error=None):
    self._response.ok = False
    self._response.error = error
    self._callback(self._response)
    _fetchers.remove(self)


# method, url, headers=None, body=None, auth=None, timeout=0, file=None, callback=None
def fetch(method, url, body=None, headers=None, auth=None, timeout=None, file=None, callback=None):
  global _fetchers
  fetcher = Fetcher(method, url, body, headers, auth, timeout, file, callback)
  _fetchers.append(fetcher)

def get(url, body=None, headers=None, auth=None, timeout=None, file=None, callback=None):
  fetch("GET", url, body, headers, auth, timeout, file, callback)

# give active fetchers a chance to process their work
def tick():
  for fetcher in _fetchers:
    fetcher.tick()