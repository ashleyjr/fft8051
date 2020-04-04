from uart import uart
from printer import printer
import math
import random
import numpy as np
import scipy.fftpack
import matplotlib.pyplot as plt

print "Test begins"

N = 64
u = uart()

d = []
s = []
for i in range(N):
    t = float(i)/N
    v  = int(10*np.sin(10*t*math.pi))
    v += int(10*np.sin(200*t*math.pi))
    d.append(v + 128)
    s.append(v)

fft_py = np.abs(scipy.fftpack.fft(s, n=N) / (N/2))
x = np.fft.fftfreq(N, d=1)

for i in range(N):
    print d[i]
    u.tx(d[i])


fft_uart = []
for i in range(N):
    r = u.rx()
    r += u.rx()*256
    print i,r
    fft_uart.append(r)

u.finish()

plt.subplot(2, 1, 1)
plt.scatter(x,fft_py)
plt.xlim([-0.5,0.5])
plt.subplot(2, 1, 2)
plt.scatter(x,fft_uart)
plt.xlim([-0.5,0.5])
plt.show()

print "Test ends"
