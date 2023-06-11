#ifndef __MY_GRAPH_SP_H__
#define __MY_GRAPH_SP_H__
#include <stdio.h>
#include <limits.h>
#define MAX_VERTICES 100
//���Ͽ� ����� �����ͷ� ����ġ �׷��� ����
void ADJ_Create(const char* g_file, int weight_mat[][MAX_VERTICES])
{
	FILE* file;
	fopen_s(&file, g_file, "r"); //read mode
	if (file == NULL) {
		printf("������ �����ϴ�. ���α׷��� �����մϴ�.");
		return;
	}
	while (1) {
		int i, j, w;
		int result = fscanf_s(file, "%d, %d, %d", &i, &j, &w);
		if (result == EOF) break;
		weight_mat[i][j] = w;
		weight_mat[j][i] = w;
	}
	fclose(file);
}
//����Լ�
void ADJ_Print_Array(int weight_mat[][MAX_VERTICES], int n)
{
	for (int i = -1; i < n; i++)
	{
		for (int j = -1; j < n; j++)
		{
			
			if (i == -1) {
				if (j == -1)		printf("     ");
				else printf("%3d ",j);
			}
			else {
				if (j == -1)	printf("%4d ", i);
				else {
					if (weight_mat[i][j] == INT_MAX)
					{
						printf("INF ");
					}
					else printf("%3d ", weight_mat[i][j]);
				}
			}
		}
		printf("\n");
	}
	printf("\n");
}
//�ִܰŸ� ���� �Լ�
void Shortest_Path(int weight_mat[][MAX_VERTICES], int n, int v, int* path)
{
	int* distance = new int[n];
	int* visited = new int[n];

	for (int i = 0; i < n; i++)
	{
		distance[i] = weight_mat[v][i];
		path[i] = v;
		visited[i] = 0;
	}
	visited[v] = 1;
	distance[v] = 0;
	int step = 1;
	int min;
	int k;
	while (step < n)
	{
		min = INT_MAX;
		for (int i = 0; i < n; i++) {
			if ((visited[i] == 0) && (distance[i] < min))
			{
				min = distance[i];
				k = i;
			}
		}
		visited[k] = 1;
		for (int u = 0; u < n; u++)
		{
			if (visited[u] == 0)
			{
				if (weight_mat[k][u] == INT_MAX)
				{
					continue;
				}
				if (distance[k] + weight_mat[k][u] < distance[u]) // INT_MAX �Ѿ�� ����� �ȵ�.
				{
					distance[u] = distance[k] + weight_mat[k][u];
					path[u] = k;
				}
			}
		}
		step = step + 1;
	}
	for (int i = 0; i < n; i++)
	{
		printf("���� 0 -> ���� %d: %d\n", i, distance[i]);
	}
}
void PrintPath(int* path, int v, int u) {
	if (u == v) {
		printf("%d ", u);
		return;
	}
	PrintPath(path, v, path[u]);
	printf("-> %d ", u);
}
#endif