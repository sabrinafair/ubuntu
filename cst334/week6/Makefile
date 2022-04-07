all: threadSync p_c alphabet_step2

threadSync: threadSync.c
	gcc -o threadSync threadSync.c -Wall -pthread

alphabet_step2: alphabet_step2.c
	gcc -o alphabet_step2 alphabet_step2.c -Wall -pthread
p_c: p_c.c
	gcc -o p_c p_c.c -Wall -pthread
clean:
	rm -f threadSync p_c alphabet_step2
