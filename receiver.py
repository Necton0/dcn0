import socket

server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

server.bind(("localhost", 5000))

print("Server waiting...")

filename, addr = server.recvfrom(1024)

filename = filename.decode()

try:
    file = open(filename, "rb")

    while True:

        data = file.read(1024)

        if not data:
            break

        server.sendto(data, addr)

    server.sendto(b"END", addr)

    file.close()


except:
    server.sendto(b"File not found", addr)

server.close()
