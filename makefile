SCALE=2
LOG2N=6

all:
	rm -rf common/Ws.h
	python common/lib/python/Ws.py > common/Ws.h ${LOG2N} ${SCALE}
	sdcc -c common/fft8051.c -I common/ -DLOG2N=${LOG2N} -DSCALE=${SCALE}
	sdcc src/main.c fft8051.rel -I inc/ -I common/ -DLOG2N=${LOG2N} -DSCALE=${SCALE} --iram-size 256 --xram-size 256 

clean:
	-rm -f main.asm
	-rm -f main.ihx
	-rm -f main.lk
	-rm -f main.lst
	-rm -f main.map
	-rm -f main.mem
	-rm -f main.rel
	-rm -f main.rst
	-rm -f main.sym
