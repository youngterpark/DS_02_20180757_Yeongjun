#ifndef __MY__ARRAY_STACK_HPP__
#define __MY__ARRAY_STACK_HPP__
#include <cstdio>
#include <cstdlib>
#define STACK_LEN 100
template <typename T> // 템플릿: 다양한 유형의 데이터에서 작동할 수 있는 함수와 클래스를 작성할 수 있음
class ArrStack { // 배열 스택 클래스 정의
private: // 클래스에서만 쓰는 변수
	T* arr; // 다양한 유형의 데이터(정수, 문자열)을 가지는 배열
	int length; // 배열 길이
	int top; // top 인덱스
public: // public
	ArrStack() { //길이 지정안하면
		top = -1; // top은 -1(스택 초기값)
		length = STACK_LEN; // STACK_LEN 기본 100 (#define)
		arr = new T[STACK_LEN]; // arr 초기화
	}
	ArrStack(int len) { //길이 따로 지정하면
		top = -1;
		length = len; // 그 길이로
		arr = new T[len];
	}
	void Stack_Init() // 배열 스택 초기화
	{
		arr[top] = -1; //
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
		if (Stack_IsEmpty()){ //비어있다면,
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
		return arr[top] == -1;
	}
	bool Stack_IsFull() // 스택이 가득 차 있는지 확인
	{
		return arr[top] == length;
	}
}; //Array Stack 클래스 선언

#endif // ! __MY__ARRAY_STACK_HPP__
