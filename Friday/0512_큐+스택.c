// 회문 판정 문제('1+1+1+1', 'racecar')의 구현 = 큐 + 스택

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
		printf("스택가득!!\n");
		return;
	}
	(s->top)++;
	s->stack[(s->top)] = data;
}

void EnQ(Q* q, char data)
{
	if ((q->rear + 1) % MAX == q->front)
	{
		printf("큐가득!\n");
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
	q.rear = 0; // 일반적으로 배열 q는 원형으로 만드나, 넉넉하게(100) 만들어서 단방향으로 만듦.

	printf("문자열을 입력하세요 : ");
	scanf("%s", str);

	for (int k = 0; k < strlen(str); k++)
	{
		Push(&s,str[k]);
		EnQ(&q,str[k]);
	}
	while ((s.top!=-1) && (q.front != q.rear)) //스택 큐 똑같이 만들어서 일치하는지 보는거다. 정상적으로 입력하면 동시에 끝남.
	{
		if (POP(&s) != DeQ(&q))
		{
			printf("%s : 회문이 아니다\n", str);
			return;
		}
	}
	printf("%s : 회문\n", str);
}