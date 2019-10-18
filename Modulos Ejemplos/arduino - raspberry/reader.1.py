'''
>>> mystring = "hello"
>>> print(mystring[0])
h
>>> print(mystring[:1])
h
>>> print(mystring[3])
l
>>> print(mystring[-1])
o
>>> print(mystring[2:3])
l
>>> print(mystring[2:4])
ll

import serial
ser = serial.Serial('/dev/ttyACM0', 9600)
while 1:
    if(ser.in_waiting >0):
        line = ser.readline()
        print(line)

'''
import serial
humidity = H
ser = serial.Serial('/dev/ttyACM0', 9600)
while 1:
    if(ser.in_waiting >0):
        line = ser.readline()
        if(line[0] = humidity):
            print(line)
        