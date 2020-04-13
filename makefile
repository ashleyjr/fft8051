SCALE=10000
LOG2N=6

all:
	rm -rf common/Ws.h
	python common/lib/python/Ws.py > common/Ws.h ${LOG2N} ${SCALE}	
	sdcc -c common/fft8051.c -I common/ -DLOG2N=${LOG2N} -DSCALE=${SCALE}
	sdcc  src/main.c fft8051.rel -I inc/ -I common/ -DLOG2N=${LOG2N} -DSCALE=${SCALE} --iram-size 256 --xram-size 256 	

compare:
	rm -rf common/Ws.h
	python common/lib/python/Ws.py > common/Ws.h ${LOG2N} ${SCALE}
	gcc -o model.o -pedantic model/src/main.c common/fft8051.c -I common/ -DLOG2N=${LOG2N} -DSCALE=${SCALE}
	sdcc -c common/fft8051.c -I common/ -DLOG2N=${LOG2N} -DSCALE=${SCALE}
	sdcc  src/main.c fft8051.rel -I inc/ -I common/ -DCOMPARE -DLOG2N=${LOG2N} -DSCALE=${SCALE} --iram-size 256 --xram-size 256 	

clean:
	rm -f common/Ws.h
	rm -f *.o
	rm -f *.asm
	rm -f *.ihx
	rm -f *.lk
	rm -f *.lst
	rm -f *.map
	rm -f *.mem
	rm -f *.rel
	rm -f *.rst
	rm -f *.sym
