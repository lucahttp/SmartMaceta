import paho.mqtt.client as mqtt

broker_address = "localhost"
client = mqtt.Client('Publicador_ejem1') # Creación del cliente
client.connect(broker_address)
topic = "#"

client.publish(topic, "Ejemplo desde Python")
