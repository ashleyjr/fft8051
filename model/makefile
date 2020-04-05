SCALE=64
LOG2N=6

all:
	rm -rf ../common/Ws.h
	python ../common/lib/python/Ws.py > ../common/Ws.h ${LOG2N} ${SCALE}
	gcc -o main.o -pedantic src/main.c ../common/fft8051.c -I ../common/ -DLOG2N=${LOG2N} -DSCALE=${SCALE}
