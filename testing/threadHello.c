//Name: Sabrina Ferras
//Date: 4-5-2022
//Title: Lab5 - Working with a Multi-Threaded program
//Description: This is the code given in step 1 of lab 5 and we are supposed to complile and run it 

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *go(void *);
#define NTHREADS 10
pthread_t threads[NTHREADS];
int main(){
	int i;
	for(i = 0; i < NTHREADS; i++)
		pthread_create(&threads[i], NULL, go, &i);	
	
	for(i = 0; i < NTHREADS; i++){
		printf("Thread %d returned\n", i);	
		pthread_join(threads[i], NULL);
	}
	printf("Main thread done.\n");
	return 0;
}

void *go(void *arg){
	printf("Hello from thread %d with iteration %d\n", (int) pthread_self(), *(int *)arg);
	return 0;
}
