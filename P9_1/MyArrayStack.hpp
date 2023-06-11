#ifndef __MY__ARRAY_STACK_HPP__
#define __MY__ARRAY_STACK_HPP__
#include <cstdio>
#include <cstdlib>
#define STACK_LEN 100
template <typename T> // ���ø�: �پ��� ������ �����Ϳ��� �۵��� �� �ִ� �Լ��� Ŭ������ �ۼ��� �� ����
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
	void Stack_Init() // �迭 ���� �ʱ�ȭ
	{
		for (int i = 0; i < STACK_LEN; i++) {
			arr[i] = 0;
		}
	}
	void Stack_Push(T item) // ������ ����
	{
		if (!Stack_IsFull()) { // ������ ���� �ʴٸ�,

			top++;
			arr[top] = item;
		}
		else {
			printf("Stack is full!\n");
			exit(1);
		}
	}
	T Stack_Pop() // ������ ����
	{
		int idx;
		if (Stack_IsEmpty()) { //����ִٸ�,
			printf("Stack is empty!\n");
			exit(1);
		}
		else {
			idx = top;
			top--;
			return arr[idx];
		}
	}
	T Stack_Peek() // �ֻ�� ������ Ȯ��
	{
		return arr[top];
	}
	bool Stack_IsEmpty() // ������ ����ִ��� Ȯ��
	{
		return top == -1;
	}
	bool Stack_IsFull() // ������ ���� �� �ִ��� Ȯ��
	{
		return top == length - 1;
	}
}; //Array Stack Ŭ���� ����

#endif // ! __MY__ARRAY_STACK_HPP__