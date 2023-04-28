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
	int pri; // 우선순위 지정할 변수 선언
	switch (op) { 
	case '*': // * 과 / 는 3 (가장 높은 우선순위)
	case '/':
		pri = 3;
		break;
	case '+': // + 와 - 는 2
	case '-':
		pri = 2;
		break;
	case '(': // ( 는 1
		pri = 1;
		break;
	default: // 나머진 -1
		pri = -1;
		break;
	}
	return pri; // 우선순위 출력
}
void Infix2Postfix(const char* infix_exp, char* postfix_exp) // 중위식->후위식 변환
{
	ArrStack<char> stack;
	stack.Stack_Init(); // 스택 초기화
	int post_index = 0;

	int len = strlen(infix_exp); // 중위식 길이만큼, 중위식 한 자씩 변환
	for (int i = 0; i < len; i++) // 중위식 길이만큼
	{
		char token = infix_exp[i]; // 토큰 = 중위식 한 자
		if (IsDigit(token)) // 토큰이 숫자이면
		{
			postfix_exp[post_index] = token; //후위식에 출력
			post_index++; // 후위식 인덱스 ++
		}
		else if (IsOperator(token)) // 토큰이연산자라면
		{
			while (!stack.Stack_IsEmpty() && Priority(token) <= Priority(stack.Stack_Peek()))
			{ // 스택이 비어 있지 않고, 토큰의 우선순위가 스택 탑 데이터 우선순위보다 작거나 같다면
				postfix_exp[post_index] = stack.Stack_Pop(); // 우선순위 낮은 스택 POP해서 후위식에 넣기
				post_index++; //후위식 넣을때마다 인덱스 업데이트
			}
			stack.Stack_Push(token); // 스택에 토큰 PUSH
		}

		else if (token == '(') // 토큰이 ( 이면
		{
			stack.Stack_Push(token); // 스택에 토큰 푸쉬
		}
		else if (token == ')') // 토큰이 ) 이면
		{
			while (stack.Stack_Peek() != '(') // ( 나올때까지
			{
				postfix_exp[post_index] = stack.Stack_Pop(); // POP해서 후위식에 넣기
				post_index++;
			}
			stack.Stack_Pop(); // (나오면, POP해서 버리기
		}
	}
	while (!stack.Stack_IsEmpty()) // 스택이 비어있지 않다면, 남아있다면
	{
		postfix_exp[post_index] = stack.Stack_Pop(); // POP해서 후위식에기넣기
		post_index++; // 인덱스 업데이트
	}
	postfix_exp[post_index] = '\0'; // 널 문자 추가. 袴袴袴袴果羲? 출력 문제 해결용.
}

int Eval_Postfix(char* postfix_exp) // 후위식 계산 및 결과
{
	ArrStack<int> stack; // 배열 선언
	stack.Stack_Init(); // 배열 초기화
	int len = strlen(postfix_exp); // 후위식 길이
	int result; // 연산한 결과

	for (int i = 0; i < len; i++) // 후위식 문자열 길이만큼 반복
	{
		char token = postfix_exp[i]; // 토큰 하나 뽑음
		if (IsDigit(token)) { // 토큰이 숫자면
			stack.Stack_Push(token-48); // ASCII 코드 문자열-> 숫자, -48해주면 됨(0~9) // 스택에 푸쉬
		}
		else if (IsOperator(token)) // 토큰이 연산자면 
		{
			int op2 = stack.Stack_Pop(); // 스택에서 팝 뒤에 먼저 ( - , / 를 위해서)
			int op1 = stack.Stack_Pop(); // 스택에서 팝 앞 숫자

			switch (token) // 토큰(연산자) switch case
			{
			case '+': // + 일 때
				result = op1 + op2; // 더해서
				stack.Stack_Push(result); // 결과 저장
				break;
			case '-': // - 일 때
				result = op1 - op2; // 빼서
				stack.Stack_Push(result); // 결과 저장
				break;
			case '*': // * 일 때
				result = op1 * op2; // 곱해서
				stack.Stack_Push(result); // 결과 저장
				break;
			case '/': // / 일 때
				result = op1 / op2; // 나눠서
				stack.Stack_Push(result); // 결과 저장
				break;
			default:
				break;
			}
		}
	}
	return stack.Stack_Pop(); // 마지막 계산된 결과값 팝
}
int main(void) { // 메인 코드
	char exp[] = "(2+5)*(3+4)-(2+(7-5))"; // 계산할 수식
	char* postfix = new char[strlen(exp) + 1]; // 후위식 변환 결과

	//1) 중위식에서 후위식으로 변환
	Infix2Postfix(exp, postfix); // 중위식에서 후위식으로 변환
	printf("Infix: %s\n", exp); // 중위식 출력
	printf("Postfix: %s\n", postfix); // 변환 결과 출력

	//2) 변환된 후위식을 계산
	int result = Eval_Postfix(postfix); // 결과 = 후위식 계산
	printf("%s = %d \n", postfix, result); // 결과 
	return 0;
}

// 고찰
