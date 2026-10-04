# Write a program to implement echo server using UDP socket.

import socket

server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

server.bind(("localhost", 5000))

print("UDP Echo Server is running...")

while True:
    data, address = server.recvfrom(1024)

    print("Client:", data.decode())

    server.sendto(data, address)
