#ifndef __MY_MAX_HEAP_TREE_HPP__
#define __MY_MAX_HEAP_TREE_HPP__
#include <cstdlib>
#include <cstdio>
#include <cmath>
//����Ʈ�� ��� �Լ�
void PrintTree2Matrix(int** M, int* bTree, int size, int idx, int col, int row, int height) {
	if (idx > size) return;
	M[row][col] = bTree[idx];
	PrintTree2Matrix(M, bTree, size, idx * 2, col - pow(2, height - 2), row + 1, height - 1);
	PrintTree2Matrix(M, bTree, size, idx * 2 + 1, col + pow(2, height - 2), row + 1, height - 1);
}
void TreePrinter(int* bTree, int size) {
	int h = (int)ceil(log2(size + 1));
	int col = (1 << h) - 1;
	int** M = new int* [h];
	for (int i = 0; i < h; i++) {
		M[i] = new int[col];
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < col; j++) {
			M[i][j] = 0;
		}
	}
	for (int j = 0; j < col; j++) {
		printf("==");
	}
	printf("\n");
	PrintTree2Matrix(M, bTree, size, 1, col / 2, 0, h);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < col; j++) {
			if (M[i][j] == 0) {
				printf("  ");
			}
			else {
				printf("%2d", M[i][j]);
			}
		}
		printf("\n");
	}
	for (int j = 0; j < col; j++) {
		printf("==");
	}
	printf("\n");
}

// �ִ� �� Ʈ�� ����/���� �Լ�
void Max_Heap_Insert(int* heap, int* h_size, int key)
{
	*h_size = *h_size + 1;
	int index = *h_size;
	while (index != 1)
	{
		if (key > heap[index / 2])
		{
			heap[index] = heap[index / 2];
			index = index / 2;
		}
		else
		{
			break;
		}
	}
	heap[index] = key;
}
int Max_Heap_Remove(int* heap, int* h_size)
{
	int deleted_key = heap[1];
	int tmp = heap[*h_size];
	*h_size = *h_size - 1;
	int parent = 1;
	int index = 2;
	while (index <= *h_size)
	{
		if (index < *h_size && heap[index + 1] > heap[index])
		{
			index = index + 1;
		}
		if (tmp >= heap[index])
		{
			break;
		}
		heap[parent] = heap[index];
		parent = index;
		index = index * 2;
	}
	heap[parent] = tmp;
	return deleted_key;
}
#endif // !__MY_MAX_HEAP_TREE_HPP__
