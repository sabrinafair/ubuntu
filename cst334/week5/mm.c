#include <stdio.h>
#include <stdlib.h>

#define N 2
#define M 3
#define L 2

//void display(int **arr, int r, int c){
//	for(int i = 0; i < r; i++){
//		for(int j = 0; j < c; j++){
//		printf("array[%d][%d]=%f\t", i, j, arr[i][j]);
//		}
//	printf("\n");
//	}
//}

void display(double arr[N][M]){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
		printf("array[%d][%d]=%f\t", i, j, arr[i][j]);
		}
	printf("\n");
	}
}
void display1(double arr[M][L]){
	for(int i = 0; i < M; i++){
		for(int j = 0; j < L; j++){
		printf("array[%d][%d]=%f\t", i, j, arr[i][j]);
		}
	printf("\n");
	}
}

void display2(double arr[N][L]){	//"DOESN'T WORK"
	for(int i = 0; i < N; i++){
		for(int j = 0; j < L; j++){
		printf("array[%d][%d]=%f\t", i, j, arr[i][j]);
		}
	printf("\n");
	}
}
int main(){
	double matrixA[N][M] = { { 1 , 2 , 3} ,
				 { 4 , 5, 6}};
	double matrixB[M][L] = { {7, 8},
				 {9, 10},
				 {11, 12}};
	double matrixC[N][M];
	
//	initMatrices();	
	
	//"Displaying matrices
	printf("Matrix A:\n");
	display(matrixA);
	printf("\nMatrix B: \n");
	display1(matrixB);
	
	printf("\n");
	
	//"MULTIPLY
	double temp = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < L; j++){
			for(int k = 0; k < M; k++){
				temp+= matrixA[i][k] * matrixB[k][j];
			}
			matrixC[i][j] = temp;
			temp = 0;
		}
	}
//	display2(matrixC);
	printf("Matrix C:\n");
	for(int i = 0; i < N; i++){
		for(int j = 0; j < L; j++){
		printf("array[%d][%d]=%f\t", i, j, matrixC[i][j]);
		}
	printf("\n");
	}
	
	
	return 0;
}
