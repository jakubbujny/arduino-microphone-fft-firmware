import threading

import serial
import time
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from matplotlib import style

buff1 = []

def readSerial():
    counter = 0

    with serial.Serial('/dev/cu.usbmodem14101', 115200, timeout=1) as ser:
        start = time.time()
        while True:
            buff = ""
            try:
                buff = ser.read(1000)   # read a '\n' terminated line
            except:
                print("read error")
            if(len(buff) > 2):
                out = []
                subList = [buff[n:n+2] for n in range(0, len(buff), 2)]
                for sample in subList:
                    number = sample[1] * 256 + sample[0]
                    out.append(number)
                    global buff1
                    buff1 = out




x = threading.Thread(target=readSerial, args=())
x.start()

while not len(buff1) > 2:
    continue

def get_data():
    xs = []
    ys = []
    if(len(buff1) > 2):
        for i, value in enumerate(buff1):
            xs.append(i)
            ys.append(value)
    return xs,ys

def init_data():
    xs = []
    ys = []
    for i in range(500):
        xs.append(i)
        ys.append(i*2 % 1024)
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