from uart import uart
from printer import printer
import math
import random
import time

print "Test begins"
LEN = 100
u = uart()
p = printer()
p.loopStart()
max_error = -1

for i in range(LEN):

    re0 = random.uniform(-100,100)
    im0 = random.uniform(-100,100)
    re1 = random.uniform(-100,100)
    im1 = random.uniform(-100,100)

    u.floatTx(re0)
    u.floatTx(im0)
    u.floatTx(re1)
    u.floatTx(im1)

    a = complex(re0, im0)
    b = complex(re1, im1)

    c = a * (a + b)

    d = complex(u.floatRx(),u.floatRx())

    e = abs(c - d)
    p.setMessage(str(i)+"/"+str(LEN))
    if e > max_error:
        max_error = e



p.loopStop()
print "Worst error: " +str(e)
u.finish()
print "Test ends"
