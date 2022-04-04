#include <stdlib.h>
#include <pthread.h>

void *thread();
void initMatrices( double a[N][M], double b[M][L]);

int main(){
int N, M, L = 10;
double matrixA[N][M];
double matrixB[M][L];
double matrixC[N][L];

initMatrices(matrixA, matrixB);


}
void *thread(){
for(int j = 0; j < L; j++){
	double temp = 0;
	for(int k = 0; k < M; k++){
		temp += matrixA[i][k] * matrixB[k][j];
	}
	matrixC[i][j] = temp;
}
}

void initMatrices( double a[N][M], double b[M][L]){
printf("Matrices A and B:\n");
srand(time(NULL));
for(int i = 0; i < N; i++){
	for(int j = 0; j < M; j++){
	matrixA[i][j] = rand();
	printf("%d\t", matrixA[i][j]);
	}
	printf("\n");
}
}
srand(time(NULL));
for(int i = 0; i < M; i++){
	for(int j = 0; j < L; j++){
	matrixB[i][j] = rand();
	printf("%d\t", matrixB[i][j]);
	}
	printf("\n");
}
