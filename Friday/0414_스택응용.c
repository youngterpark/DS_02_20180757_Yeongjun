#include <stdio.h>
#include <string.h>

#define Max_Size 100 //���� �ִ� ����
typedef double element;
element stack[Max_Size];
int top = -1;

int isFull() // ������ ���� á���� Ȯ��
{
	return top == Max_Size - 1;
}

int isEmpty() // ������ ������� Ȯ��
{
	return top == -1;
}

void PUSH(element item) // ���ÿ� item�� �����Ѵ�.
{
	if (isFull())
	{
		printf("������ ����!!!\n");
		return -1;
	}
	top++;
	stack[top] = item;
}

element POP() // ���ÿ��� item�� ��ȯ �� ����
{
	if (isEmpty())
	{
		printf("������ �����.\n");
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
			PUSH(temp - 48); //�ƽ�Ű�ڵ� ����
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
		printf("������ �Է�: ");
		scanf("%s", infix);
		Infix_to_Postfix(infix, postfix);

		printf("������: %s\n", postfix);

		double re=Result(postfix);

		printf("�����: %lf\n", re);
	}
}
