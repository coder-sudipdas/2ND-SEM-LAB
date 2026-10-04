import socket

client = socket.socket()
client.connect(("localhost", 8000))

request = "GET /file.txt HTTP/1.1\r\nHost: localhost\r\n\r\n"
client.send(request.encode())

data = client.recv(4096)

print(data.decode(errors="ignore"))

client.close()

