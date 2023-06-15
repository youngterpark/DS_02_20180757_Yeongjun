// ȸ�� ���� ����('1+1+1+1', 'racecar')�� ���� = ť + ����

#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct S
{
	char stack[MAX];
	int top;
}S;

typedef struct Q
{
	char queue[MAX];
	int front;
	int rear;
}Q;

void Push(S* s, char data)
{
	if (s->top == MAX - 1)
	{
		printf("���ð���!!\n");
		return;
	}
	(s->top)++;
	s->stack[(s->top)] = data;
}

void EnQ(Q* q, char data)
{
	if ((q->rear + 1) % MAX == q->front)
	{
		printf("ť����!\n");
		return;
	}
	q->rear = (q->rear + 1) % MAX;
	q->queue[q->rear] = data;
}

char POP(S* s)
{
	if (s->top == -1)
	{
		return 0;
	}

	return s->stack[(s->top)--];
}

char DeQ(Q* q)
{
	if (q->front == q->rear)
	{
		return 0;
	}
	q->front = (q->front + 1) % MAX;
	return q->queue[q->front];
}

void main()
{
	char str[MAX];
	S s;
	Q q;

	s.top = -1;
	q.front = 0;
	q.rear = 0; // �Ϲ������� �迭 q�� �������� ���峪, �˳��ϰ�(100) ���� �ܹ������� ����.

	printf("���ڿ��� �Է��ϼ��� : ");
	scanf("%s", str);

	for (int k = 0; k < strlen(str); k++)
	{
		Push(&s,str[k]);
		EnQ(&q,str[k]);
	}
	while ((s.top!=-1) && (q.front != q.rear)) //���� ť �Ȱ��� ���� ��ġ�ϴ��� ���°Ŵ�. ���������� �Է��ϸ� ���ÿ� ����.
	{
		if (POP(&s) != DeQ(&q))
		{
			printf("%s : ȸ���� �ƴϴ�\n", str);
			return;
		}
	}
	printf("%s : ȸ��\n", str);
}