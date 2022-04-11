all: threadSync alphabet_step2

threadSync: threadSync.c
	gcc -o threadSync threadSync.c -Wall -pthread

alphabet_step2: alphabet_step2.c
	gcc -o alphabet_step2 alphabet_step2.c -Wall -pthread
clean:
	rm -f threadSync alphabet_step2
