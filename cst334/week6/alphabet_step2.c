//Name: Sabrina Ferras
//Date: 4-8-2022
//Title: Lab 6 - Producer Consumer program to produce and consume the alphabet
//Description: This program makes threads (a producer and consumer thread) to produce letters (printing out which letter was produces) A - B and to consume the letters and print them to output
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define N 26	//amount of letters in the alphabet

sem_t empty;
sem_t full;
sem_t mutex;

int buffer[N];	//to hold the letters
int fill = 0;	//used the format from the book for the put and get
int use = 0;
int itemsConsumed = 26;
#define NTHREADS 1
pthread_t p[NTHREADS];
pthread_t c[NTHREADS];
int asciiPlace = 65;	//one less than the beginning of the uppercase alphabet
int loops = 26;
void put(int value){
	buffer[fill] = value;
	fill = (fill + 1) % N;
}

int get(){
	int tmp = buffer[use];
	use = (use + 1) % N;
	return tmp;
}

void *producer(void *arg){
	do{
	if(asciiPlace > 90) break;	//to exit out of the loop
	int i = asciiPlace++;
	sem_wait(&empty);
	sem_wait(&mutex);
	put(i);
	printf("Producer thread producing letter: %c\n", i);
	sem_post(&mutex);
	sem_post(&full);
	sleep(1);
	}while(1);
	
}

void *consumer(void *arg){
	char tmp;	//I added
	do{
	if(loops <= 0) break;
	sem_wait(&full);
	sem_wait(&mutex);
	tmp = get();
	sem_post(&mutex);
	sem_post(&empty);
	printf("Consumer thread consuming: %c\n", tmp);
	loops--;
	sleep(1);
	}while(1);
}

int main(int argc, char *argv[]){

	sem_init(&empty, 0, N);
	sem_init(&full, 0, 0);
	sem_init(&mutex, 0, 1);	//set to one for lock
	int i;
	for(i = 0; i < NTHREADS; i++){	//creating the producer and consumer threads
		pthread_create(&p[i], NULL, producer, (void *)NULL);
		pthread_create(&c[i], NULL, consumer, (void *)NULL);
	}

	for(i = 0; i < NTHREADS; i++){	//waiting for the producer and consumer threads
		pthread_join(p[i], NULL);
		pthread_join(c[i], NULL);
	}

	sem_destroy(&empty);
	sem_destroy(&full);
	sem_destroy(&mutex);
}
