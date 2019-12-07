import threading

import serial
import time
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from matplotlib import style

buff = []

def readSerial():
    with serial.Serial('/dev/cu.usbmodem14101', 115200, timeout=1) as ser:
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

while not len(buff) > 2:
    #print("wait for sync")
    continue

def get_data():
    xs = []
    ys = []
    if(len(buff) > 2):
        for i, value in enumerate(buff):
            xs.append(i)
            ys.append(value)
    return xs,ys

def init_data():
    xs = []
    ys = []
    for i in range(500):
        xs.append(i)
        ys.append(i*2)
    return xs,ys

fig, ax = plt.subplots()
xs,ys = init_data()
line, = ax.plot(xs, ys)


def animate(j):
    xs,ys = get_data()
    line.set_xdata(xs)
    line.set_ydata(ys)
    return line,


ani = animation.FuncAnimation(
    fig, animate, interval=200)


plt.show()