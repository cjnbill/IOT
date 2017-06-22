import socket
import time
import paho.mqtt.client as mqtt

def on_connect(client, userdata, rc):
	print("Connected with result code " + str(rc))
	client.subscribe("Button")
	
def on_message(client, userdata, msg):
	print "on_message called with topic: ", msg.topic + ", message: " + str(msg.payload)
	dst = ('192.168.3.13', 8001) # BBB address
	userdata.sendto(str(msg.payload), dst)


# Set the socket of edge
edge_address = '10.136.39.74'
address = (edge_address, 8000)
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.bind(address)

# connect to the server
# client_id = "", clean_session = True, userdata = s (in on_message)
mqttc = mqtt.Client("", True, s)
mqttc.on_connect = on_connect
mqttc.on_message = on_message

mqttc.connect("128.227.170.197")
mqttc.loop_start() # start a new thread to handle network loop

print "Start listening to device status change"

while True:
	data, addr = s.recvfrom(2048)
	if not data:
		continue
	print "received: ", data, " from ", addr
	device, status = data.split(' ')
	mqttc.publish(device, status)

s.close()


	



    
