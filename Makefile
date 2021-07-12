CC=gcc

nya:
	$(CC) nyax.c -o nyax

clean:
	-rm nyax

all: clean nya
