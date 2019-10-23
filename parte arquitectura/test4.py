import paho.mqtt.client as mqtt #import the client1
broker_address="localhost"
port_number=1883
#gg
client = mqtt.Client()

client.connect(broker_address) #connect to broker
client.publish("arduino","ON")#publish