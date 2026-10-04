import socket
import os

server = socket.socket()
server.bind(("localhost", 8000))
server.listen(1)

print("Server is running...")

while True:
    conn, addr = server.accept()

    request = conn.recv(4096).decode(errors="ignore")
    print(request)

    if request.startswith("GET"):
        filename = "file.txt"

        if os.path.exists(filename):
            with open(filename, "rb") as f:
                data = f.read()

            response = b"HTTP/1.1 200 OK\r\n\r\n" + data
        else:
            response = b"HTTP/1.1 404 Not Found\r\n\r\nFile not found"

        conn.sendall(response)

    conn.close()
    