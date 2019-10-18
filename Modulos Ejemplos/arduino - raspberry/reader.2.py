'''
%IC
%ICI2
@PICI2
#GG3
%ICI3
@PICI3
#GG4
%ICI4
@PICI4
#GG5
%ICI5
@PICI5
#GG0
%ICI0

'''
import serial
encoding = 'utf-8'
humidity = '@'
ser = serial.Serial('COM4', 9600)
#ser1 = serial.Serial('/dev/ttyACM0', 9600)
while 1:
    line = str(ser.readline(), encoding)
    #print(line)
    if(line[0] == '@'):
        print(line)

