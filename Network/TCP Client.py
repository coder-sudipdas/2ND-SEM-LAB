# Write a program to implement echo client using TCP socket.

import socket

client = socket.socket()
client.connect(("localhost", 5000))

while True:
    msg = input("Enter message: ")

    client.send(msg.encode())

    if msg == "exit":
        break

    reply = client.recv(1024).decode()
    print("Echo from server:", reply)

client.close()
print("Client closed")

