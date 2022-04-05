all: matrixMultiply
#all: threadHello threadHello_step1 matrix 
matrixMultiply: matrixMultiply.c
	gcc -o matrixMultiply matrixMultiply.c -Wall -pthread

threadHello: threadHello.c
	gcc -o threadHello threadHello.c -Wall -pthread

threadHello_step1: threadHello_step1.c
	gcc -o threadHello_step1 threadHello_step1.c -Wall -pthread

matrix: matrix.c
	gcc -o matrix matrix.c -Wall -pthread

clean:
	rm -f threadHello threadHello_step1 matrix threadM2
