#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* thread(void* arg);
void initMatrices();
void display();
int N, M, L = 10;
double matrixA[N][M];
double matrixB[M][L];
double matrixC[N][L];

int part = 0; 	//to keep track of where we are in the matrix
int main(){

initMatrices();
pthread_t threads[N];
for(int i = 0; i < N; i++){
	pthread_create(&threads[i], NULL, thread, (void*)NULL);
}
//to wait for theads
for(int i = 0; i < N; i++){
	pthread_join(threads[i], NULL);
}

display(matrixC);

}
void* thread(void* arg){
for(int j = 0; j < L; j++){
	double temp = 0;
	for(int k = 0; k < M; k++){
		temp += matrixA[j][k] * matrixB[k][j];
	}
	matrixC[j][k] = temp;
}


void initMatrices(){
printf("Matrices A and B:\n");
srand(time(NULL));
for(int i = 0; i < N; i++){
	for(int j = 0; j < M; j++){
	matrixA[i][j] = rand();
	printf("%f\t", matrixA[i][j]);
	}
	printf("\n");
}
}
srand(time(NULL));
for(int i = 0; i < M; i++){
	for(int j = 0; j < L; j++){
	matrixB[i][j] = rand();
	printf("%f\t", matrixB[i][j]);
	}
	printf("\n");
}

void display(){
for(int i = 0; i < N; i++){
	for(int j = 0; j < L; j++){
	printf("%f\t", matrixC[i][j]);
	}
	printf("\n");
}
}
