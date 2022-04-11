//Name: Sabrina Ferras
//Date: 4-5-2022
//Lab: Lab 5 - Working with threads
//Description: This step 3 of the lab demonstrates how to implement threads to work in parrallel to solve a matrix multiplication
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 1024
#define M 1024
#define L 1024

pthread_t threads[N];

void multiply(double matrixA[N][M], double matrixB[M][L], double matrixC[N][L], int currentRow){

	double temp = 0;
	for(int i = currentRow; i < currentRow + 1; i++){
		for(int j = 0; j < L; j++){
			for(int k = 0; k < M; k++){
				temp+= matrixA[i][k] * matrixB[k][j];
			}
			matrixC[i][j] = temp;
			temp = 0;
		}
	}

}

void initMatrices(double a[N][M], double b[M][L]){
	srand(time(NULL));
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			a[i][j] = rand();

	srand(time(NULL));
	for(int i = 0; i < M; i++)
		for(int j = 0; j < L; j++)
			b[i][j] = rand();
}	

void display(int r ,int c, double arr[r][c]){
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
		printf("array[%d][%d]=%f\t", i, j, arr[i][j]);
	}
	printf("\n");
	}
}

struct matrices{
	double matrixA[N][M];
	double matrixB[M][L];
	double matrixC[N][M];
};

struct matrices *mtx;// = malloc(sizeof(struct matrices));

void *thread(void* arg){
	int rn = *(int *)arg;
	//"MULTIPLY
	multiply(mtx->matrixA, mtx->matrixB, mtx->matrixC, rn);
	free(arg);
}

int main(){
	mtx = malloc(sizeof(struct matrices));
	initMatrices(mtx->matrixA, mtx->matrixB);	
	
	//"Displaying matrices
	printf("Matrix A:\n");
	display(N, M, mtx->matrixA);
	printf("\nMatrix B: \n");
	display(M, L, mtx->matrixB);
	
	//"Creating threads
	for(int i = 0; i < N; i++){	//creating n threads to do n rows of the C matrix
		int *arg = malloc(sizeof(int));
		*arg = i;
		pthread_create(&threads[i], NULL, thread, arg); 		
	}
	
	//"wait to print --JOIN
	for(int i = 0; i < N; i++)
		pthread_join(threads[i], NULL);

	printf("Matrix C:\n");
	display(N, L, mtx->matrixC);

	free(mtx);	//frr malloc'd space
	
	return 0;
}
