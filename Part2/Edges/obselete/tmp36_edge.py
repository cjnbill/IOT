import socket
import time
import paho.mqtt.client as mqtt

def on_connect(client, userdata, rc):
	print("Connected with result code " + str(rc))

# Set the socket of edge
edge_address = '192.168.0.1'
address = (edge_address, 8000)
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.bind(address)

# connect to the server
# client_id = "", clean_session = True, userdata = s (in on_message)
mqttc = mqtt.Client("", True, s)
mqttc.on_connect = on_connect

mqttc.connect("128.227.170.197")
mqttc.loop_start()

print "Start listening to device status change"

while True:
	data, addr = s.recvfrom(2048)
	if not data:
		continue
	print "received: ", data, " from ", addr
	mqttc.publish("Tmp36", data)

s.close()



    