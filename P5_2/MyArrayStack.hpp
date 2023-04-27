#ifndef __MY__ARRAY_STACK_HPP__
#define __MY__ARRAY_STACK_HPP__
#include <cstdio>
#include <cstdlib>
#define STACK_LEN 100
template <typename T> // 템플릿: 다양한 유형의 데이터에서 작동할 수 있는 함수와 클래스를 작성할 수 있음
class ArrStack {
private:
	T* arr; // 다양한 데이터(정수, 문자열) 받을 수 있는 배열;
	int length; // 배열 길이
	int top; // top 인덱스
public:
	ArrStack() { // 길이 따로 지정 안하면
		top = -1; // top 초기값 -1
		length = STACK_LEN; // 길이 = STACK_LEN = 100
		arr = new T[STACK_LEN]; // 배열 동적할당
	}
	ArrStack(int len) { // 길이 따로 정하면
		top = -1; // top 초기값 -1
		length = len; // 지정한 길이로 길이 지정
		arr = new T[len]; // 배열 동적할당
	}
	void Stack_Init() // 배열 스택 초기화
	{
		for (int i = 0; i < STACK_LEN; i++) { // 배열 길이만큼
			arr[i] = 0; // 0으로 초기화
		}
	}
	void Stack_Push(T item) // 데이터 삽입
	{
		if (!Stack_IsFull()) { // 가득차 있지 않다면,

			top++; // top 인덱스 올리고
			arr[top] = item; // top에 새로운 데이터 삽입
		}
		else {
			printf("Stack is full!\n"); // 가득차 있다면
			exit(1); // 프로그램 종료
		}
	}
	T Stack_Pop() // 데이터 인출
	{
		int idx; // 인덱스 선언
		if (Stack_IsEmpty()){ // 비어있다면,
			printf("Stack is empty!\n"); 
			exit(1); // 프로그램 종료
		}
		else { // 비어있지 않다면,
			idx = top; // 인덱스에 현재 top 저장한 후
			top--; // top 인덱스 1 빼기
			return arr[idx]; // 빼기 전 top이었던 데이터 인출
		}
	}
	T Stack_Peek() // 최상단 데이터 확인
	{
		return arr[top]; // top 위치 데이터 return
	}
	bool Stack_IsEmpty() // 스택이 비어있는지 확인
	{
		return top == -1; // top이 -1이면 True or False
	}
	bool Stack_IsFull() // 스택이 가득 차 있는지 확인
	{
		return top == length-1; // top이 길이 - 1인지 아닌지 True or False
	}
}; //Array Stack 클래스 선언

#endif // ! __MY__ARRAY_STACK_HPP__
