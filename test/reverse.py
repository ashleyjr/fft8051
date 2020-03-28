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
    n    = random.randrange(1,14)
    size = 2 ** n
    num  = random.randrange(0,size)

    p.setMessage(str(i)+"/"+str(LEN))

    u.floatTx(size)
    u.floatTx(num)
    rev = int(u.floatRx())
    a = format(num, '#032b')[-n-1:]
    b = format(rev, '#032b')[-n-1:]
    for i in range(0, n+1):
        if a[i] != b[n - i]:
            print "Error: "
            print n
            print a
            print b
p.loopStop()
u.finish()
print "Test ends"
