import paho.mqtt.client as mqtt

broker_url = "localhost"
broker_port = 1883

client = mqtt.Client()
client.connect(broker_url, broker_port)
client.publish(topic="TestingTopic", payload="TestingPayload", qos=2, retain=False)