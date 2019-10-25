import serial
ser = serial.Serial('COM6', 9600)
ser.write(b'@')
ser.close()
