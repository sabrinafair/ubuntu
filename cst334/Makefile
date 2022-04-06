all: threadHello threadHello_step2 matrixMultiply threadHello_with_lock

matrixMultiply: matrixMultiply.c
	gcc -o matrixMultiply matrixMultiply.c -Wall -pthread

threadHello: threadHello.c
	gcc -o threadHello threadHello.c -Wall -pthread

threadHello_step2: threadHello_step2.c
	gcc -o threadHello_step2 threadHello_step2.c -Wall -pthread

threadHello_with_lock: threadHello_with_lock.c
	gcc -o threadHello_with_lock threadHello_with_lock.c -Wall -pthread

clean:
	rm -f threadHello threadHello_step2 matrixMultiply
