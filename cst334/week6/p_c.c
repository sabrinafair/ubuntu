//Name: Sabrina Ferras
//Date: 4-7-2022
//Title: Lab 6 - Producer Consumer program to produce and consume the alphabet
//Description: This program makes threads to produce letters A - B and threads to consume (print) the letters 
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

pthread_t p[N];
pthread_t c[N];
int asciiPlace = 65;	//the beginning of the uppercase alphabet

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
	sem_wait(&empty);
	sem_wait(&mutex);
	put(asciiPlace);
	asciiPlace++;
	sem_post(&mutex);
	sem_post(&full);
}

void *consumer(void *arg){
	char tmp;	//I added
	sem_wait(&full);
	sem_wait(&mutex);
	tmp = get();
	sem_post(&mutex);
	sem_post(&empty);
	printf("%c\n", tmp);
}

int main(int argc, char *argv[]){

	sem_init(&empty, 0, N);
	sem_init(&full, 0, 0);
	sem_init(&mutex, 0, 1);	//set to one for lock
	int i;
	for(i = 0; i < N; i++){	//creating the producer and consumer threads
		pthread_create(&p[i], NULL, producer, (void *)NULL);
		pthread_create(&c[i], NULL, consumer, (void *)NULL);
	}

	for(i = 0; i < N; i++){	//waiting for the producer and consumer threads
		pthread_join(p[i], NULL);
		pthread_join(c[i], NULL);
	}

	sem_destroy(&empty);
	sem_destroy(&full);
	sem_destroy(&mutex);
}
