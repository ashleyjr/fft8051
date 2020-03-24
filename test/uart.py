import serial
import serial.tools.list_ports
import time
import sys
import random
import threading
import time
from optparse import OptionParser
import math

class uart:
    BAUDRATE= 230400
    RX_BUFFER_SIZE = 1024

    def __init__(self):
        ports =  serial.tools.list_ports.comports()
        found = ""
        self.name = ""
        for port, desc, hwid in sorted(ports):
            if "C232" in desc:
                found = port
                self.name = port + ": " + desc
                break

        self.ser = serial.Serial(
            port=found,
            baudrate=self.BAUDRATE,
            parity=serial.PARITY_NONE,
            stopbits=serial.STOPBITS_ONE,
            bytesize=serial.EIGHTBITS
        )

        self.rx_buf = [0] * self.RX_BUFFER_SIZE
        self.rx_buf_head = 0
        self.rx_buf_tail = 0

        self.stop = False
        threading.Thread(target=self.rx_buffer).start()

    def getName(self):
        return self.name

    def rx_buffer(self):
        while not self.stop:
            while(self.ser.inWaiting() != 0):
                self.rx_buf[self.rx_buf_head] = ord(self.ser.read(1))
                self.rx_buf_head += 1
                self.rx_buf_head %= self.RX_BUFFER_SIZE

    def tx(self, d):
        self.ser.write(chr(d))
        time.sleep(0.001)
        return

    def rx(self):
        while(self.rx_buf_tail == self.rx_buf_head):
            pass
        d = self.rx_buf[self.rx_buf_tail]
        self.rx_buf_tail += 1
        self.rx_buf_tail %= self.RX_BUFFER_SIZE
        return d

    def rxWaiting(self):
        return self.rx_buf_head - self.rx_buf_tail

    def clearRx(self):
        while(self.rx_buf_tail != self.rx_buf_head):
            self.rx()

    def finish(self):
        self.stop = True
        return

    def floatTx(self, t):
        ''' Build an IEEE 754 '''
        if (t < 0):
            s = 1
        else:
            s = 0
        f = abs(t)
        e = int(math.floor(math.log(f+1e-24, 2)))
        f = f * (2 ** -e)
        m = int(f * (2 ** 23))
        f = (s << 31) |\
            (((e + 127) & 0xFF) << 23) |\
            (m & 0x7FFFFF)
        ''' MSB first '''
        for i in range(4):
            self.tx((f >> 24) & 0xFF)
            f = f << 8

    def floatRx(self):
        ''' MSB first '''
        f = 0
        for i in range(3):
            f |= self.rx()
            f = f << 8
        f |= self.rx()
        ''' Build an IEEE 754 float '''
        s = (f >> 31) & 0x1
        e = ((f >> 23) & 0xFF) - 127
        m = 1 + ((f & 0x7FFFFF) * (2 ** -23))
        return  ((-1) ** s) * (2 ** e) * m


