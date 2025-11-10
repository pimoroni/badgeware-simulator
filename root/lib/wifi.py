import network
import time

_timeout = None
_on_success = None
_on_error = None
wlan = None

def tick():
  global _timeout, _on_success, _on_error

  if wlan.isconnected() and _on_success:
    _on_success()
    _timeout = None
    _on_success = None
    _on_timeout = None
    return

  if _timeout and time.ticks_ms() > _timeout and _timeout:
    # connection timeout
    wlan.active(False)
    _on_error()
    _timeout = None
    _on_success = None
    _on_timeout = None

def connect(ssid, psk, timeout=30, on_success=None, on_error=None):
  global wlan, _timeout, _on_success, _on_error

  if wlan and wlan.isconnected():
    return True

  if wlan is None:
    wlan = network.WLAN(network.STA_IF)
    wlan.active(True)
    wlan.connect(ssid, psk)
    _on_success = on_success
    _on_error = on_error
    _timeout = time.ticks_ms() + (timeout * 1000)

def is_connected():
  return wlan is not None and wlan.isconnected()

def ip():
  assert False, "TODO: WLAN.ifconfig() not implemented in emulator"
  info = wlan.ifconfig()
  return info[0]

def subnet():
  assert False, "TODO: WLAN.ifconfig() not implemented in emulator"
  info = wlan.ifconfig()
  return info[1]

def gateway():
  assert False, "TODO: WLAN.ifconfig() not implemented in emulator"
  info = wlan.ifconfig()
  return info[2]

def nameserver():
  assert False, "TODO: WLAN.ifconfig() not implemented in emulator"
  info = wlan.ifconfig()
  return info[3]