import threading

import serial
import time
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from matplotlib import style

buff = []

with open("rec.csv", "w"):
    pass

counter = 0
def readSerial():
    with serial.Serial('/dev/cu.usbmodem14101', 115200, timeout=1) as ser:
        while True:
            line = ""
            try:
                line = ser.readline().decode("utf-8")   # read a '\n' terminated line
            except:
                print("read error")
            if len(line.split(",")[0]) > 0:
                if line.split(",")[0][0] != "b":
                    print("not in sync, continue")
                    continue
            global buff, counter
            print("in sync!")
            counter += 1
            if counter == 62:
                break
            with open("rec.csv", "a+") as file:
                file.write(line)

readSerial()
