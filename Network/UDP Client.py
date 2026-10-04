# Write a program to implement echo client using UDP socket.

import socket

client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

while True:
    msg = input("Enter message: ")

    if msg == "exit":
        break

    client.sendto(msg.encode(), ("localhost", 5000))

    data, address = client.recvfrom(1024)

    print("Echo from server:", data.decode())

client.close()


