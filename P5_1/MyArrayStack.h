#ifndef __MY__ARRAY_STACK_H__
#define __MY__ARRAY_STACK_H__
#include <cstdio>
#include <cstdlib>
#define STACK_LEN 100
typedef enum { F, T }Bool; // Bool 타입 정의
typedef int Data; // Data 타입 정의
typedef struct MyArrayStack { // 스택 정의
	Data arr[STACK_LEN]; // 스택 길이 만큼 Data 넣을 배열 정의
	int top; // 젤 위 데이터를 가리키는 top 정의
}ArrStack; // Array Stack 구조체 선언
void Stack_Init(ArrStack* pStack); // 배열 스택 초기화
void Stack_Push(ArrStack* pStack, Data item); // 데이터 삽입
Data Stack_Pop(ArrStack* pStack); // 데이터 인출
Data Stack_Peek(ArrStack* pStack); // 최상단 데이터 확인
Bool Stack_IsEmpty(ArrStack* pStack); // 스택이 비어있는지 확인
Bool Stack_IsFull(ArrStack* pStack); // 스택이 가득 차 있는지 확인
#endif