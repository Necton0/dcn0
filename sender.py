import socket

client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

filename = input("Enter file name: ")

client.sendto(filename.encode(), ("localhost", 5000))

file = open("received_" + filename, "wb")

while True:

    data, addr = client.recvfrom(1024)

    if data == b"END":
        break

    file.write(data)

file.close()

print("File received successfully")

client.close()
