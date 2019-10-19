import paho.mqtt.client as mqttClient
import time
import serial
encoding = 'utf-8'
humidity = '@'
ser = serial.Serial('COM4', 9600)
#ser1 = serial.Serial('/dev/ttyACM0', 9600)
#https://techtutorialsx.com/2017/04/14/python-publishing-messages-to-mqtt-topic/
def on_connect(client, userdata, flags, rc):
 
    if rc == 0:
 
        print("Connected to broker")
 
        global Connected                #Use global variable
        Connected = True                #Signal connection 
 
    else:
 
        print("Connection failed")
 
Connected = False   #global variable for the state of the connection
 
broker_address= "localhost"
port = 1883
user = ""
password = ""
 
client = mqttClient.Client("Python")               #create new instance
#client.username_pw_set(user, password=password)    #set username and password
client.on_connect= on_connect                      #attach function to callback
client.connect(broker_address, port=port)          #connect to broker
 
client.loop_start()        #start the loop
 
while Connected != True:    #Wait for connection
    time.sleep(0.1)
 
try:
    while True:
        
        #value = input('Enter the message:')
        #client.publish("python/test",value)
        line = str(ser.readline(), encoding)
        if(line[0] == '@'):
            print ("Soy El Primer Parametro")
            print line.split(",",-1)[1] 
            print ("Soy El Segundo Parametro")
            print line.split(",",-1)[2] 
            print ("Soy El Tercer Parametro")
            print line.split(",",-1)[3] 
 
except KeyboardInterrupt:
 
    client.disconnect()
    client.loop_stop()




import serial
encoding = 'utf-8'
humidity = '@'
ser = serial.Serial('COM4', 9600)
#ser1 = serial.Serial('/dev/ttyACM0', 9600)
while 1:
    line = str(ser.readline(), encoding)
    #print(line)
    if(line[0] == '@'):
        print ("Soy El Primer Parametro")
        print line.split(",",-1)[1] 
        print ("Soy El Segundo Parametro")
        print line.split(",",-1)[2] 
        print ("Soy El Tercer Parametro")
        print line.split(",",-1)[3] 