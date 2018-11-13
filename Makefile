run: bs
	./bs
	
bs: bs.c
	gcc -Wall -std=c11 bs.c -o bs

build: bs
