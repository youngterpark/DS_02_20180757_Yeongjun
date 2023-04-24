#include <iostream>
#include "MyArrayStack.h"

void Stack_Init(ArrStack* pStack) // �迭 ���� �ʱ�ȭ
{
	pStack->top = -1; // �ʱ�ȭ: top = -1;
}
void Stack_Push(ArrStack* pStack, Data item) // ������ ����
{
	if (!Stack_IsFull(pStack)) { // ������ ���� �ʴٸ�
		pStack->top = pStack->top + 1; // top 1 ���
		pStack->arr[pStack->top] = item; // ��µ� top ĭ�� item ����
	}
	else
	{
		printf("Stack is Full\n"); // ������ �����Ƿ� ���� ����
		exit(1); // ���α׷� ����
	}
}
Data Stack_Pop(ArrStack* pStack) // ������ ����
{
	int idx; // POP�� ���� ������ top idx
	if (Stack_IsEmpty(pStack)) { // ��� �ִٸ�
		printf("Stack is empty!\n"); // ��������Ƿ� POP �Ұ�
		exit(1); // ���α׷� ����
	}
	else {
		idx = pStack->top; // idx�� ���� top
		pStack->top--; // top 1 ����
		return pStack->arr[idx]; //���� top�� POP
	}
}
Data Stack_Peek(ArrStack* pStack) // �ֻ�� ������ Ȯ��
{
	return pStack->arr[pStack->top]; // top ��ġ Data return
}
Bool Stack_IsEmpty(ArrStack* pStack) // ������ ����ִ��� Ȯ��
{
	if (pStack->top == -1) // top�� �ʱⰪ�� -1�̸� �����
	{
		return T; // T
	}
	else
	{
		return F; // �ƴ� F
	}
}
Bool Stack_IsFull(ArrStack* pStack) // ������ ���� �� �ִ��� Ȯ��
{
	if (pStack->top == STACK_LEN) // top �� ���� ���� �̸�
	{
		return T; // T
	}
	else
	{
		return F; // F
	}
}