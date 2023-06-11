#ifndef __MY__ARRAY_STACK_HPP__
#define __MY__ARRAY_STACK_HPP__
#include <cstdio>
#include <cstdlib>
#define STACK_LEN 100
template <typename T> // 템플릿: 다양한 유형의 데이터에서 작동할 수 있는 함수와 클래스를 작성할 수 있음
class ArrStack {
private:
	T* arr;
	int length;
	int top;
public:
	ArrStack() {
		top = -1;
		length = STACK_LEN;
		arr = new T[STACK_LEN];
	}
	ArrStack(int len) {
		top = -1;
		length = len;
		arr = new T[len];
	}
	void Stack_Init() // 배열 스택 초기화
	{
		for (int i = 0; i < STACK_LEN; i++) {
			arr[i] = 0;
		}
	}
	void Stack_Push(T item) // 데이터 삽입
	{
		if (!Stack_IsFull()) { // 가득차 있지 않다면,

			top++;
			arr[top] = item;
		}
		else {
			printf("Stack is full!\n");
			exit(1);
		}
	}
	T Stack_Pop() // 데이터 인출
	{
		int idx;
		if (Stack_IsEmpty()) { //비어있다면,
			printf("Stack is empty!\n");
			exit(1);
		}
		else {
			idx = top;
			top--;
			return arr[idx];
		}
	}
	T Stack_Peek() // 최상단 데이터 확인
	{
		return arr[top];
	}
	bool Stack_IsEmpty() // 스택이 비어있는지 확인
	{
		return top == -1;
	}
	bool Stack_IsFull() // 스택이 가득 차 있는지 확인
	{
		return top == length - 1;
	}
}; //Array Stack 클래스 선언

#endif // ! __MY__ARRAY_STACK_HPP__