import paho.mqtt.client as mqtt
def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+str(rc))
    client.subscribe("cosasosas")
def on_message(client, userdata, msg):
    print(msg.topic+" "+str(msg.payload))

client = mqtt.Client(client_id="luca")
client.on_connect = on_connect
client.on_message = on_message

client.connect("192.168.3.27", 1883, 60)
client.subscribe("cosasosas")
client.loop_forever()
#client.loop_start()  # usar este si se esta probando desde ipython
