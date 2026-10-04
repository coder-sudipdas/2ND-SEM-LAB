# Write a program to implement echo Server using TCP socket.
import socket

server = socket.socket()
server.bind(("localhost", 5000))
server.listen(1)

print("Server is running...")

conn, addr = server.accept()
print("Client connected")

while True:
    msg = conn.recv(1024).decode()

    if msg == "exit":
        break

    print("Received:", msg)
    conn.send(msg.encode())

conn.close()
server.close()
print("Server closed")

