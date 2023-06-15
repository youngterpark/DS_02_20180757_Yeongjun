#include <stdio.h>

#define VERTEX 7
#define SIZE 10

int queue[SIZE];
int front = 0, rear = 0;

void Enq(int V)
{
	if (front == (rear + 1) % SIZE)
	{
		return;
	}
	rear = (rear + 1) % SIZE;
	queue[rear] = V;
}

int Is_empty()
{
	return front == rear;
}

int Deq()
{
	if (Is_empty())
	{
		return  -1;
	}
	front = (front + 1) % SIZE;
	return queue[front];
}

void Insert_edge(int v_mat[VERTEX][VERTEX], int start, int end)
{
	v_mat[start][end] = 1; // �길 �ϸ� ���� �׷���
	v_mat[end][start] = 1; // ������ �׷���
}

void Dfs_sear(int v_mat[VERTEX][VERTEX], int V, int dfs_visited[])
{
	dfs_visited[V] = 1;
	printf("%3d ->", V);
	for (int w = 0; w < VERTEX; w++)
	{
		if (v_mat[V][w] && !dfs_visited[w])
		{
			Dfs_sear(v_mat, w, dfs_visited);
		}
	}
}

void Bfs_sear(int v_mat[VERTEX][VERTEX], int V, int bfs_visited[])
{
	bfs_visited[V] = 1;
	printf("%3d ->", V);
	Enq(V);
	while (!Is_empty())
	{
		V = Deq();
		for (int w = 0; w < VERTEX; w++)
		{
			if (v_mat[V][w] && !bfs_visited[w])
			{
				bfs_visited[w] = 1;
				Enq(w);
				printf("%3d ->", w);
			}
		}
	}
}

void main()
{
	int v_mat[VERTEX][VERTEX] = { 0 };
	int dfs_visited[VERTEX][VERTEX] = { 0 } , bfs_visited[VERTEX][VERTEX] = { 0 };

	Insert_edge(v_mat, 0, 1);
	Insert_edge(v_mat, 0, 2);
	Insert_edge(v_mat, 1, 3);
	Insert_edge(v_mat, 1, 4);
	Insert_edge(v_mat, 2, 3);
	Insert_edge(v_mat, 2, 5);
	Insert_edge(v_mat, 3, 4);
	Insert_edge(v_mat, 3, 5);
	Insert_edge(v_mat, 4, 6);
	Insert_edge(v_mat, 5, 6);

	printf("���� �켱 : ");
	Dfs_sear(v_mat, 0, dfs_visited);
	printf("\n�ʺ� �켱 : ");
	Bfs_sear(v_mat, 4, bfs_visited);
}

// �߰���� ���� ����. ���� ����~�׷��� ����
// ���� ���� �׷���
// ����ġ�� ��� ����
// : ���ʰ��, ���ڵ� ���� ��, �� �ڵ� ���ÿ�. �˰��� �˰� �ְ�, �ڵ� �м�(�ձ����� ��Ÿ��)
// ���ÿ�. 

// �� �ڵ� ��� �ִ� �κ� ä���.