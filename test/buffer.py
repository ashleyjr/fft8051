from uart import uart
from printer import printer
import math
import random
import time

print "Test begins"
LEN = 200
u = uart()
p = printer()
p.loopStart()
max_error = -1


sent = []
while not u.rxWaiting():
    ii = random.randrange(0,255)
    u.tx(ii)
    sent.append(ii)

print "Sent:" + str(len(sent))

time.sleep(2)

rxed = 0
while u.rxWaiting():
    r = u.rx()
    s = sent[rxed]
    if s != r:
        print "Error: i=" + str(rxed) + ": " + str(s) + " != " + str(r)
    rxed += 1

print "Got: " + str(rxed)
p.loopStop()
u.finish()
print "Test ends"
