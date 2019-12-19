import threading

import serial
import time

with open("rec.csv", "w"):
    pass

counter = 0
buff = []
def readSerial():
    with serial.Serial('/dev/cu.usbmodem14101', 115200, timeout=1) as ser:
        while True:
            line = []
            try:
                line = ser.read(1002)
            except:
                print("read error")
            output = "b,"
            if len(line) == 1002:
                for i in range(0,1000):
                    output += str(line[i]) + ","
            else:
                print(len(line))
            global counter, buff
            counter += 1
            if counter == 30:
                break
            output += "\n"
            buff += output

readSerial()

with open("rec.csv", "a+") as file:
    for el in buff:
        file.write(el)