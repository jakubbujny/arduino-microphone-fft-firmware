import threading

import serial
import time
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from matplotlib import style

buff = []

with open("rec.csv", "w"):
    pass

out = []
def readSerial():
    counter = 0

    with serial.Serial('/dev/cu.usbmodem14101', 115200, timeout=1) as ser:
        start = time.time()
        while True:
            buff = []
            try:
                buff = ser.read(1200)   # read a '\n' terminated line
            except:
                print("read error")

            if len(buff) > 2:
                output = []
                subList = [buff[n:n+2] for n in range(0, len(buff), 2)]
                for sample in subList:
                    number = sample[1] * 256 + sample[0]
                    output.append(number)
                line = ""
                if output[0] > 1024:
                    continue
                for b in output:
                    line += str(b) + ","
                line += "\n"
                counter += 1
                if counter == 40:
                    break
                global out
                out += line

        end = time.time()
        print(end - start)


readSerial()

with open("rec.csv", "a+") as file:
    for line in out:
        file.write(line)