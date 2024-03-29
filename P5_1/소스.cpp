// 실습과제 5.1
// 배열 스택을 구현해보자
// void Stack_Init(ArrStack* pStack); //배열 스택 초기화
// void Stack_Push(ArrStack* pStack, Data item); //데이터 삽입
// Data Stack_Pop(ArrStack* pStack); //데이터 인출
// Data Stack_Peek(ArrStack* pStack); //최상단 데이터 확인
// Bool Stack_IsEmpty(ArrStack* pStack); //스택이 비어있는지 확인
// Bool Stack_IsFull(ArrStack* pStack); //스택이 가득 차 있는지 확인


#include <iostream>
#include "MyArrayStack.h"
using namespace std;

int main(void) {
	ArrStack stack; // 스택 생성
	// 스택 초기화
	Stack_Init(&stack); // 스택 초기화 (top -1)
	// 데이터 삽입
	Stack_Push(&stack, 5); // 5 삽입
	Stack_Push(&stack, 7); // 7 삽입
	Stack_Push(&stack, 8); // 8 삽입
	Stack_Push(&stack, 9); // 9 삽입
	Stack_Push(&stack, 2); // 2 삽입
	// top 데이터 확인
	printf("top: %d\n", Stack_Peek(&stack));
	// 데이터 인출
	while (!Stack_IsEmpty(&stack)) { // 빌 때 까지
		printf("%d\n", Stack_Pop(&stack)); // POP 출력
	}
	return 0;
}
// 고찰
// 배열로 후입선출 데이터 구조인 스택을 구현하였다.
// 배열의 끝은 스택의 맨 위를 나타낸다.
// 배열을 사용하여 스택을 구현하는 것은 고정된 크기로 PUSH, POP에 제한 사항이 있습니다. (참고로, 배열과 달리 연결리스트 스택은 PUSH할 경우 isFull()을 확인하지 않는다.)
