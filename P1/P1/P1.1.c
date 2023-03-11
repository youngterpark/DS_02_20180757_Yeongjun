// n X n 행렬이 주어졌을 때 이 행렬의 전치 행렬을 구하는 알고리즘을 구현하여라.
// 입력: n X n 으로 구성된 2차원 행렬 A
// 출력: 행렬 A의 전치 행렬 B

#include <stdio.h>
#define MAT_SIZE 5

void Transpose_Mat(int A[][MAT_SIZE], int B[][MAT_SIZE]) {
	int i, j;

	for (i = 0; i < MAT_SIZE; i++) {
		for (j = 0; j < MAT_SIZE; j++) {
			B[i][j] = A[j][i];
		}
	}
}

void Print_Mat(int arr[][MAT_SIZE]) {
	int i, j;

	for (i = 0; i < MAT_SIZE; i++) {
		for (j = 0; j < MAT_SIZE; j++) {
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int A[5][5] = { {3,2,6,4,5},
		{8,3,5,9,1},
		{0,3,2,7,9},
		{2,1,5,2,4},
		{5,0,8,2,3} };
	int B[MAT_SIZE][MAT_SIZE];

	Transpose_Mat(A, B);
	Print_Mat(A);
	printf("\n");
	Print_Mat(B);

	return 0;
}
