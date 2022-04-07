all: threadSync p_c

threadSync: threadSync.c
	gcc -o threadSync threadSync.c -Wall -pthread

p_c: p_c.c
	gcc -o p_c p_c.c -Wall -pthread
clean:
	rm -f threadSync p_c
