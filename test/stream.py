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

N = 32
H = 170
u = uart()

''' Run on MCU '''
u = uart()
''' Lock '''
#getLock()
while(1):
    while(True):
        a = u.rx()
        if(a == 255):
            break

    rs = []
    for i in range(N):
        rs.append(u.rx())
    print rs
    for i in range(N):
        for r in rs:
            if (r > ((N-i)*(float(H)/N))):
                print "#",
            else:
                print " ",
        print ""
    for r in rs:
        if(r > 0):
            print "#",
        else:
            print " ",
    print ""

print "Test ends"
