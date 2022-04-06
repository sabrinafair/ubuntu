//Name: Sabrina Ferras
//Date: 4-5-2022
//Title: Lab5 - Working with a Multi-Threaded program
//Description: 

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *go();
#define NTHREADS 10
pthread_t threads[NTHREADS];
pthread_mutex_t mutex;	//added for to have a lock for critical sections

int num = 0;

int main(){
	pthread_mutex_init(&mutex, NULL);	//initialize lock
	int i;
	for(i = 0; i < NTHREADS; i++){
		pthread_create(&threads[i], NULL, go, NULL);
	}
	for(i = 0; i < NTHREADS; i++){
		printf("Thread %d returned\n", i);
		pthread_join(threads[i], NULL);
	}
	printf("Main thread done.\n");
	pthread_mutex_destroy(&mutex);
	return 0;
}

void *go(){
	pthread_mutex_lock(&mutex);
	printf("Hello from thread %d with iteration %d\n", (int) pthread_self(), num);
	num++;
	pthread_mutex_unlock(&mutex);
	return 0;
}
