// n X n ����� �־����� �� �� ����� ��ġ ����� ���ϴ� �˰����� �����Ͽ���.
// �Է�: n X n ���� ������ 2���� ��� A
// ���: ��� A�� ��ġ ��� B

#include <stdio.h>
// MAT_SIZE = n x n ����� n���� 5�� define
#define MAT_SIZE 5

// ��� A�� ��ġ����� ����Ͽ� ��� B�� �����ϴ� �Լ�
void Transpose_Mat(int A[][MAT_SIZE], int B[][MAT_SIZE]) {
	int i, j;

	// ��ġ����� ������ ���� ����
	// "��� B�� �� = ��� A�� ��, ��� B�� �� = ��� A�� ��"���� ����
	for (i = 0; i < MAT_SIZE; i++) {
		for (j = 0; j < MAT_SIZE; j++) {
			B[i][j] = A[j][i];
		}
	}
}

// ����� ����ϴ� �Լ�
void Print_Mat(int arr[][MAT_SIZE]) {
	int i, j;

	// 2���� �ึ�� �ٹٲ� ���ָ鼭 ���� ������ŭ ���
	for (i = 0; i < MAT_SIZE; i++) {
		for (j = 0; j < MAT_SIZE; j++) {
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}
}

// main �Լ�
int main() {
	// 5 X 5�� ��� A�� �Է�(������)���� ����
	int A[5][5] = { {3,2,6,4,5},
		{8,3,5,9,1},
		{0,3,2,7,9},
		{2,1,5,2,4},
		{5,0,8,2,3} };
	// ��� A�� ��ġ��ķ� ������� ��� B ����
	int B[MAT_SIZE][MAT_SIZE];

	// ��ġ��� ����Լ� ����
	Transpose_Mat(A, B);
	// ��� A ���
	Print_Mat(A);
	printf("\n");
	// ��� B ���
	Print_Mat(B);

	return 0;
}
