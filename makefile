all:
	sdcc src/main.c -I inc/ --iram-size 256 --xram-size 256 --model-large 

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
