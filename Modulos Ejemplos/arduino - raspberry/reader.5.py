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
