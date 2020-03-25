import sys
import threading
import time

class printer:

    def __init__(self):
        self.update = 0.1
        self.message = ""

    def loopStart(self):
        self.req_stop = False
        self.ack_stop = False
        threading.Thread(target=self.loop).start()

    def loopStop(self):
        self.req_stop = True
        while not self.ack_stop:
            pass
        sys.stdout.write("\n\r")

    def loop(self):
        while not self.req_stop:
            time.sleep(self.update)
            sys.stdout.write("\r" + self.message)
            sys.stdout.flush()
        self.ack_stop = True

    def setMessage(self,s):
        self.message = s

