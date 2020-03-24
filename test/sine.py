from uart import uart
import math
import random
LEN = 1000
u = uart()

max_error = 0
for i in range(LEN):
    ii = random.uniform(-100,100)
    p = math.sin(ii)
    u.floatTx(ii)
    m = u.floatRx()
    e = abs(p - m)
    if e > max_error:
        print "Worst error: " +str(e)
        max_error = e

u.finish()
