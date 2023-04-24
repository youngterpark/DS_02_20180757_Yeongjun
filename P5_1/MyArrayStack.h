#ifndef __MY__ARRAY_STACK_H__
#define __MY__ARRAY_STACK_H__
#include <cstdio>
#include <cstdlib>
#define STACK_LEN 100
typedef enum { F, T }Bool; // Bool Ÿ�� ����
typedef int Data; // Data Ÿ�� ����
typedef struct MyArrayStack { // ���� ����
	Data arr[STACK_LEN]; // ���� ���� ��ŭ Data ���� �迭 ����
	int top; // �� �� �����͸� ����Ű�� top ����
}ArrStack; // Array Stack ����ü ����
void Stack_Init(ArrStack* pStack); // �迭 ���� �ʱ�ȭ
void Stack_Push(ArrStack* pStack, Data item); // ������ ����
Data Stack_Pop(ArrStack* pStack); // ������ ����
Data Stack_Peek(ArrStack* pStack); // �ֻ�� ������ Ȯ��
Bool Stack_IsEmpty(ArrStack* pStack); // ������ ����ִ��� Ȯ��
Bool Stack_IsFull(ArrStack* pStack); // ������ ���� �� �ִ��� Ȯ��
#endif