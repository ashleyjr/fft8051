SCALE=10000
LOG2N=2

all:
	rm -rf common/Ws.h	
	python tools/imageGen/imageGen.py --line1 fft --line2 8051 --var disp_fft > disp/disp.h	
	python tools/imageGen/imageGen.py --line1 TEST --size 20  --var disp_test >> disp/disp.h
	python common/lib/python/Ws.py > common/Ws.h ${LOG2N} ${SCALE}	
	sdcc -c common/fft8051.c -I common/ -DLOG2N=${LOG2N} -DSCALE=${SCALE}
	sdcc  src/main.c fft8051.rel -I inc/ -I common/ -I disp/ -DLOG2N=${LOG2N} -DSCALE=${SCALE} --iram-size 256 --xram-size 256 	

compare:
	rm -rf common/Ws.h
	python common/lib/python/Ws.py > common/Ws.h ${LOG2N} ${SCALE}
	gcc -o model.o -pedantic model/src/main.c common/fft8051.c -I common/ -DLOG2N=${LOG2N} -DSCALE=${SCALE}
	sdcc -c common/fft8051.c -I common/ -DLOG2N=${LOG2N} -DSCALE=${SCALE}
	sdcc  src/main.c fft8051.rel -I inc/ -I common/ -I disp/ -DCOMPARE -DLOG2N=${LOG2N} -DSCALE=${SCALE} --iram-size 256 --xram-size 256 	

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
