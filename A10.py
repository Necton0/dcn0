import socket

print("1. Domain to IP")
print("2. IP to Domain")

choice = int(input("Enter the choice: "))

if choice==1:
  domain = input("Enter the domain name: ")
  try:
    ip = socket.gethostbyname(domain)
    print("IP Address: ", ip)
  except:
    print("Invalid domain")

elif choice==2:
  ip = input("Enter the ip address: ")
  try: 
    domain = socket.gethostbyaddr(ip)
    print("Domain Name: ",domain[0])
  except:
    print("Invalid IP")

else:
    print("Wrong Choice")
