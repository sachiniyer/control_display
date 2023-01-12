import serial
import time
import requests

ser = serial.Serial("/dev/ttyUSB0", 9600, timeout = 1)
time.sleep(2)

val = ""


def sendData(data):
    """
    This command sends data over the serial port
    """
    command = str.encode(data)
    ser.write(command)


while True:
    x = requests.get('http://localhost:3000/api/word')
    x = x.text
    if x != val:
        val = x
        sendData(val)
        print(val)
    time.sleep(5)
