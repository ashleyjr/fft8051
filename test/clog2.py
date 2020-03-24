from uart import uart
import math
import random
LEN = 1000
u = uart()

max_error = 0
for i in range(LEN):
    ii = random.uniform(1,(2 ** 32))
    p = math.ceil(math.log(ii, 2))
    u.floatTx(ii)
    m = u.floatRx()
    e = abs(p - m)
    if e > max_error:
        print "Worst error: " +str(e)
        print ii,m,p
        max_error = e

u.finish()
