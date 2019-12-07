import numpy as np
import simpleaudio as sa


fs = 8000  # 44100 samples per second
seconds = 4  # Note duration of 3 seconds

t = np.linspace(0, seconds, seconds * fs, False)

out = []
with open("rec.csv", "r") as f:
    line = f.readline()
    while line:
        strings = line.split(",")[1:-1]
        out += strings
        line = f.readline()


for i,sample in enumerate(out):
    if i == fs * seconds:
        break
    t[i] = int(sample) * 8


t = t.astype(np.int16)
# Start playback
play_obj = sa.play_buffer(t, 1, 2, fs)

# Wait for playback to finish before exiting
play_obj.wait_done()