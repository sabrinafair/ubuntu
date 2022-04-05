#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 2
#define M 3
#define L 2

pthread_t threads[N];
int currentRow = 0;

int multiply(double matrixA[N][M], double matrixB[M][L], double matrixC[N][L]){
//int multiply(){

	if(currentRow == N) return -1;

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

	currentRow++;
	return 1;
}

void initMatrices(double a[N][M], double b[M][L]){
	srand(time(NULL));
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			a[i][j] = (rand() % 10) + 1;

	srand(time(NULL));
	for(int i = 0; i < M; i++)
		for(int j = 0; j < L; j++)
			b[i][j] = (rand() % 10) + 1;
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

void *thread(struct matrices *m){
//	struct matrices *m = (struct matrices*) arg;
//	matrices *mtx = malloc(sizeof(matrices));
//	initMatrices(m->matrixA, m->matrixB);	
	printf("\nTesting Thread matrix A: \n");
	display(N, M, m->matrixA);
//	display(M , L, b);
//	display(N , L, c);
	//"MULTIPLY
	//multiply(matrixA, matrixB, matrixC);
}

int main(){
//	double matrixA[N][M];
//	double matrixB[M][L];
//	double matrixC[N][M];
	//struct matrices 
	mtx = malloc(sizeof(struct matrices));
//	Matrices *mtx = (Matrices*) matrix;
	initMatrices(mtx->matrixA, mtx->matrixB);	
	
	//"Displaying matrices
	printf("Matrix A:\n");
	display(N, M, mtx->matrixA);
	printf("\nMatrix B: \n");
	display(M, L, mtx->matrixB);
	//"Creating threads
	for(int i = 0; i < N; i++)
		pthread_create(&threads[i], NULL, thread, &mtx);		

	
	//"wait to print --JOIN
	for(int i = 0; i < N; i++)
		pthread_join(threads[i], NULL);
	printf("Matrix C:\n");
	display(N, L, mtx->matrixC);
	free(mtx);
	
	return 0;
}
