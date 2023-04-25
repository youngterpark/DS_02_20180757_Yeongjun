// 실습과제 5.2
// 배열 스택을 활용한 계산기를 구현해보자
// 아래 함수들을 구현
// 
////1) 중위식 -> 후위식 변환
//void Infix2Postfix(const char* infix_exp, char* postfix_exp);//중위식 -> 후위식 변환
//int IsDigit(char token);//숫자인지 확인
//int IsOperator(char token);//연산자인지 확인
//int Priority(char op);//우선순위 확인
// 
////2) 후위식 계산 및 결과
//int Eval_Postfix(char* postfix_exp);


#include <iostream>
#include <cstring>
#include "MyArrayStack.hpp"

using namespace std;

int IsDigit(char token) // 숫자인지 확인
{
	return (token >= '0' && token <= '9');
}
int IsOperator(char token) // 연산자인지 확인
{
	return (token == '+' || token == '-' || token == '*' || token == '/');
}
int Priority(char op) // 우선순위 확인
{
	int pri;
	switch (op) {
	case '*':
	case '/':
		pri = 3;
		break;
	case '+':
	case '-':
		pri = 2;
		break;
	case '(':
		pri = 1;
		break;
	default:
		pri = -1;
		break;
	}
	return pri;
}
void Infix2Postfix(const char* infix_exp, char* postfix_exp) // 중위식->후위식 변환
{
	ArrStack<char> stack;
	stack.Stack_Init(); // 스택 초기화
	int post_index = 0;

	int len = strlen(infix_exp);
	for (int i = 0; i < len; i++)
	{
		char token = infix_exp[i];
		if (IsDigit(token))
		{
			postfix_exp[post_index] = token;
			post_index++;
		}
		else if (IsOperator(token))
		{
			while (!stack.Stack_IsEmpty() && Priority(token) <= Priority(stack.Stack_Peek()))
			{
				postfix_exp[post_index] = stack.Stack_Pop();
				post_index++;
			}
			stack.Stack_Push(token);
		}

		else if (token == '(')
		{
			stack.Stack_Push(token);
		}
		else if (token == ')')
		{
			while (stack.Stack_Peek() != '(')
			{
				postfix_exp[post_index] = stack.Stack_Pop();
				post_index++;
			}
			stack.Stack_Pop();
		}
	}
	while (!stack.Stack_IsEmpty())
	{
		postfix_exp[post_index] = stack.Stack_Pop();
		post_index++;
	}
	postfix_exp[post_index] = '\0'; // 널 문자 추가. 袴袴袴袴果羲? 출력 문제 해결용.
}

int Eval_Postfix(char* postfix_exp) // 후위식 계산 및 결과
{
	ArrStack<int> stack;
	stack.Stack_Init();
	int len = strlen(postfix_exp);
	int result;

	for (int i = 0; i < len; i++)
	{
		char token = postfix_exp[i];
		if (IsDigit(token)) {
			stack.Stack_Push(token-48); // ASCII 코드 문자열-> 숫자, -48해주면 됨(0~9)
		}
		else if (IsOperator(token))
		{
			int op2 = stack.Stack_Pop();
			int op1 = stack.Stack_Pop();

			switch (token)
			{
			case '+':
				result = op1 + op2;
				stack.Stack_Push(result);
				break;
			case '-':
				result = op1 - op2;
				stack.Stack_Push(result);
				break;
			case '*':
				result = op1 * op2;
				stack.Stack_Push(result);
				break;
			case '/':
				result = op1 / op2;
				stack.Stack_Push(result);
				break;
			default:
				break;
			}
		}
	}
	return stack.Stack_Pop();
}
int main(void) {
	char exp[] = "(2+5)*(3+4)-(2+(7-5))"; // 계산할 수식
	char* postfix = new char[strlen(exp) + 1]; // 후위식 변환 결과

	//1) 중위식에서 후위식으로 변환
	Infix2Postfix(exp, postfix); // 중위식에서 후위식으로 변환
	printf("Infix: %s\n", exp);
	printf("Postfix: %s\n", postfix); // 변환 결과 출력

	//2) 변환된 후위식을 계산
	int result = Eval_Postfix(postfix);
	printf("%s = %d \n", postfix, result);
	return 0;
}

// 고찰
