import socket

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server.bind(("localhost", 5000))

server.listen(1)
print("Waiting for connection...")

conn, addr = server.accept()
print("Connection formed...")

filename = conn.recv(1024)
received_file = open("new_"+filename.decode(), "wb")

while True:
    data = conn.recv(1024)
    if not data:
        break
    received_file.write(data)
print("File received...")
received_file.close()
conn.close()
server.close()
