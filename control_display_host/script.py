import serial
import time

ser = serial.Serial("/dev/ttyUSB0", 9600, timeout = 1)
time.sleep(2)

# Send character 'S' to start the program
command = str.encode('ADASDO')
ser.write(command)
