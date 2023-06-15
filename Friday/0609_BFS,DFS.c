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
	v_mat[start][end] = 1; // 얘만 하면 방향 그래프
	v_mat[end][start] = 1; // 무방향 그래프
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

	printf("깊이 우선 : ");
	Dfs_sear(v_mat, 0, dfs_visited);
	printf("\n너비 우선 : ");
	Bfs_sear(v_mat, 4, bfs_visited);
}

// 중간고사 시험 범위. 스택 기초~그래프 기초
// 예상 시험 그래프
// 시험치는 방식 변경
// : 지필고사, 손코딩 조금 들어감, 빈 코드 쓰시오. 알고리즘 알고 있고, 코드 분석(손교수님 스타일)
// 쓰시오. 

// 제 코드 비어 있는 부분 채우기.