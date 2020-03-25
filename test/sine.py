from uart import uart
from printer import printer
import math
import random

print "Test begins"
LEN = 100
u = uart()
p = printer()
p.loopStart()
max_error = -1
for i in range(LEN):
    ii = random.uniform(-100,100)
    z = math.sin(ii)
    u.floatTx(ii)
    m = u.floatRx()
    e = abs(z - m)
    p.setMessage(str(i)+"/"+str(LEN))
    if e > max_error:
        max_error = e
p.loopStop()
print "Worst error: " +str(e)
u.finish()
print "Test ends"
