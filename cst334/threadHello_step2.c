//Name: Sabrina Ferras
//Date: 4-5-2022
//Title: Lab5 - Working with a Multi-Threaded program
//Description: Demonstraiting how important it is to understand what you are passing to a thread 

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *go(void* arg);
#define NTHREADS 10
pthread_t threads[NTHREADS];
int main(){
	int i;
	for(i = 0; i < NTHREADS; i++){
		int *arg = malloc(sizeof(int));	//allocating for each thread
		*arg = i;	//seting value of iteration #
		pthread_create(&threads[i], NULL, go, arg);	//try here (void *) i instreas of &i
	}
	for(i = 0; i < NTHREADS; i++){
		printf("Thread %d returned\n", i);	
		pthread_join(threads[i], NULL);
	}
	printf("Main thread done.\n");
	return 0;
}

void *go(void* arg){
	int num = *(int *)arg;
	printf("Hello from thread %d with iteration %d\n", (int) pthread_self(), num);
	free(arg);	//freeing the memory
	return 0;
}
