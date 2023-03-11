// n X n 행렬이 주어졌을 때 이 행렬의 전치 행렬을 구하는 알고리즘을 구현하여라.
// 입력: n X n 으로 구성된 2차원 행렬 A
// 출력: 행렬 A의 전치 행렬 B

#include <stdio.h>
// MAT_SIZE = n x n 행렬의 n으로 5로 define
#define MAT_SIZE 5

// 행렬 A의 전치행렬을 계산하여 행렬 B에 저장하는 함수
void Transpose_Mat(int A[][MAT_SIZE], int B[][MAT_SIZE]) {
	int i, j;

	// 전치행렬을 다음과 같이 구성
	// "행렬 B의 행 = 행렬 A의 열, 행렬 B의 열 = 행렬 A의 행"으로 구성
	for (i = 0; i < MAT_SIZE; i++) {
		for (j = 0; j < MAT_SIZE; j++) {
			B[i][j] = A[j][i];
		}
	}
}

// 행렬을 출력하는 함수
void Print_Mat(int arr[][MAT_SIZE]) {
	int i, j;

	// 2차원 행마다 줄바꿈 해주면서 열의 개수만큼 출력
	for (i = 0; i < MAT_SIZE; i++) {
		for (j = 0; j < MAT_SIZE; j++) {
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}
}

// main 함수
int main() {
	// 5 X 5의 행렬 A를 입력(고정값)으로 받음
	int A[5][5] = { {3,2,6,4,5},
		{8,3,5,9,1},
		{0,3,2,7,9},
		{2,1,5,2,4},
		{5,0,8,2,3} };
	// 행렬 A의 전치행렬로 출력해줄 행렬 B 선언
	int B[MAT_SIZE][MAT_SIZE];

	// 전치행렬 계산함수 실행
	Transpose_Mat(A, B);
	// 행렬 A 출력
	Print_Mat(A);
	printf("\n");
	// 행렬 B 출력
	Print_Mat(B);

	return 0;
}
