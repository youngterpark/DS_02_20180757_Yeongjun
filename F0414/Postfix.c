#include <stdio.h>
#include <string.h>

#define Max_Size 100 //스택 최대 길이
typedef double element;
element stack[Max_Size];
int top = -1;

int isFull() // 스택이 가득 찼는지 확인
{
	return top == Max_Size - 1;
}

int isEmpty() // 스택이 비었는지 확인
{
	return top == -1;
}

void PUSH(element item) // 스택에 item을 삽입한다.
{
	if (isFull())
	{
		printf("스택이 가득!!!\n");
		return -1;
	}
	top++;
	stack[top] = item;
}

element POP() // 스택에서 item을 반환 후 삭제
{
	if (isEmpty())
	{
		printf("스택이 비었다.\n");
		return;
	}
	element temp = stack[top]; 
	top--;
	return temp;
}

void R_p(char* postfix, int* post_index)
{
	while (1)
	{
		char temp = POP();
		if (temp != '(')
		{
			postfix[*post_index] = temp;
			(*post_index)++;
		}
		else
		{
			break;
		}
	}
}

int E(char temp)
{
	switch (temp)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	default:
		return 0;
		break;
	}
}

void oper(char* postfix, int* post_index, char temp)
{
	if (E(temp) <= E(stack[top]))
	{
		postfix[*post_index] = POP();
		(*post_index)++;
	}
	PUSH(temp);
}

void Infix_to_Postfix(char* infix, char* postfix)
{
	int post_index = 0;
	for (int k = 0; k < strlen(infix); k++)
	{
		char temp = infix[k];
		switch (temp)
		{
		case '(':
			PUSH(temp);
			break;
		case ')':
			R_p(postfix, &post_index);
			break;
		case '+':
		case '-':
		case '*':
		case '/':
			oper(postfix, &post_index, temp);
			break;
		default:
			postfix[post_index] = temp;
			post_index++;
			break;
		}
	}
	
	while (top != -1)
	{
		postfix[post_index] = POP();
		post_index++;
	}
	postfix[post_index] = '\0';
}

double Result(char* postfix)
{
	int len = strlen(postfix);
	char temp;
	double A, B;
	for (int k = 0; k < len; k++)
	{
		temp = postfix[k];
		if (temp >= '0' && temp <= '9')
		{
			PUSH(temp - 48); //아스키코드 참고
		}
		else
		{
			//A + B
			//A - B
			B = POP();
			A = POP();
			switch (temp)
			{
			case '+':
				PUSH(A + B);
				break;
			case '-':
				PUSH(A - B);
				break;
			case '*':
				PUSH(A * B);
				break;
			case '/':
				PUSH(A / B);
				break;
			default:
				break;
			}
		}
	}
	return POP();
}

void main()
{
	char infix[Max_Size], postfix[Max_Size];
	
	while (1)
	{
		printf("중위식 입력: ");
		scanf("%s", infix);
		Infix_to_Postfix(infix, postfix);

		printf("후위식: %s\n", postfix);

		double re=Result(postfix);

		printf("결과값: %lf\n", re);
	}
}
