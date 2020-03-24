all:
	sdcc src/main.c -I inc/

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
