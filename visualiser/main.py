import threading

import serial
import time
import matplotlib.pyplot as plt
import numpy as np

buff = []

def readSerial():
    with serial.Serial('/dev/cu.usbmodem141101', 115200, timeout=1) as ser:
        while True:
            line = ser.readline().decode("utf-8")   # read a '\n' terminated line
            if len(line.split(",")[0]) > 0:
                if line.split(",")[0][0] != "b":
                    print("not in sync, continue")
                    continue
            global buff
            strings = line.split(",")[1:-1]
            output = []
            for string in strings:
                output.append(int(string))
            buff = output

x = threading.Thread(target=readSerial, args=())
x.start()

plt.ion()

currentBuff = []

while True:
    if len(buff) > 2 :
        currentBuff += buff
        if len(currentBuff) < 1000:
            continue
        plt.plot(currentBuff)
        plt.draw()
        plt.pause(0.0001)
        plt.clf()
        currentBuff = []
