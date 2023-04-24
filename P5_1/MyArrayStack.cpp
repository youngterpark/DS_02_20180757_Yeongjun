#include <iostream>
#include "MyArrayStack.h"

void Stack_Init(ArrStack* pStack) // 배열 스택 초기화
{
	pStack->top = -1; // 초기화: top = -1;
}
void Stack_Push(ArrStack* pStack, Data item) // 데이터 삽입
{
	if (!Stack_IsFull(pStack)) { // 가득차 있지 않다면
		pStack->top = pStack->top + 1; // top 1 상승
		pStack->arr[pStack->top] = item; // 상승된 top 칸에 item 삽입
	}
	else
	{
		printf("Stack is Full\n"); // 가득차 있으므로 쌓지 못함
		exit(1); // 프로그램 종료
	}
}
Data Stack_Pop(ArrStack* pStack) // 데이터 인출
{
	int idx; // POP을 위한 임의의 top idx
	if (Stack_IsEmpty(pStack)) { // 비어 있다면
		printf("Stack is empty!\n"); // 비어있으므로 POP 불가
		exit(1); // 프로그램 종료
	}
	else {
		idx = pStack->top; // idx에 현재 top
		pStack->top--; // top 1 빼기
		return pStack->arr[idx]; //현재 top은 POP
	}
}
Data Stack_Peek(ArrStack* pStack) // 최상단 데이터 확인
{
	return pStack->arr[pStack->top]; // top 위치 Data return
}
Bool Stack_IsEmpty(ArrStack* pStack) // 스택이 비어있는지 확인
{
	if (pStack->top == -1) // top이 초기값인 -1이면 비었음
	{
		return T; // T
	}
	else
	{
		return F; // 아님 F
	}
}
Bool Stack_IsFull(ArrStack* pStack) // 스택이 가득 차 있는지 확인
{
	if (pStack->top == STACK_LEN) // top 이 스택 길이 이면
	{
		return T; // T
	}
	else
	{
		return F; // F
	}
}