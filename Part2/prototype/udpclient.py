import socket

address = ('192.168.3.3', 8001)
b = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
b.bind(address)


msg = "world"
dst = ('192.168.3.13', 8001)
b.sendto(msg, dst)
b.close()
