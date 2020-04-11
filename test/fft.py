from uart import uart
from printer import printer
import math
import random
import numpy as np
import scipy.fftpack
import matplotlib.pyplot as plt
import subprocess
import time

print "Test begins"

N = 64
u = uart()

''' Create sine waves '''
s = []
for i in range(N):
    t = float(i)/N
    amps  = [10, 10]
    freqs = [100, 200]
    v= int(amps[0]*np.sin(freqs[0]*t*math.pi))
    for i in range(1,len(amps)):
        v += int(amps[i]*np.sin(freqs[i]*t*math.pi))
    s.append(v)

''' FFT '''
fft_py = np.abs(scipy.fftpack.fft(s, n=N) / (N/2))
x = np.fft.fftfreq(N, d=1)

''' Model '''
cmd = "./model.o"
for i in range(N):
    t = str(s[i])
    cmd += " \"" + t + "\""
out = subprocess.check_output(cmd, shell=True)
fft_model = []
fs = out.split(",")
for f in fs:
    fft_model.append(int(f))
print fft_model

''' Run on MCU '''
u = uart()
for i in range(N):
    u.tx(s[i] + 128)
    print s[i] + 128
fft_uart = []
for i in range(N):
    r = u.rx()
    print i,r
    fft_uart.append(r)
u.finish()

''' Plot '''
plt.subplot(3, 1, 1)
plt.scatter(x,fft_py)
plt.xlim([0,0.5])

plt.subplot(3, 1, 2)
plt.scatter(x,fft_model)
plt.xlim([0,0.5])

plt.subplot(3, 1, 3)
plt.scatter(x,fft_uart)
plt.xlim([0,0.5])

plt.show()

print "Test ends"
