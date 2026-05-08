import socket

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

client.connect(("localhost", 5000))

filename = input("Enter the filename: ")
client.send(filename.encode())

file = open(filename, "rb")

while True:
    data = file.read(1024)
    if not data:
        break
    client.send(data)
file.close() 
client.close()

print("FIle Sent")
