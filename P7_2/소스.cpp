#include "MyMaxHeapTree.h"
#define MAX_HEAP_SIZE 20
int main()
{
	int maxHeap[MAX_HEAP_SIZE] = { 0,35,15,30,13,9,18,10,7,4,3, };
	int size = 10;
	TreePrinter(maxHeap, size); // �⺻ �ִ� �� Ʈ�� ���
	Max_Heap_Insert(maxHeap, &size, 50); // Ű�� 50 ����
	TreePrinter(maxHeap, size); // ���� ��� Ȯ��
	
	int tmp = Max_Heap_Remove(maxHeap, &size); // �ִ� �� ���� ����
	TreePrinter(maxHeap, size); // ���� ���� ��� Ȯ��
	printf("Deleted Key: %d\n", tmp); // ������ ��� ���
	return 0;
}