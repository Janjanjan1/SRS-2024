import socket

host = socket.gethostname()
port = 52001                   # The same port as used by the server
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((host, port))
while True:
    s.sendall(b'Hello, world')
data = s.recv(1024)
s.close()
print('Received', repr(data))
