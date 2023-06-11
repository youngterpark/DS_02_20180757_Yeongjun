#ifndef __MY_GRAPH_MST_H__
#define __MY_GRAPH_MST_H__
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
				else printf("%3d ", j);
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
//���� �˰��� ��� �ּҺ�� ����Ʈ��
void MST_Prim(int weight_mat[][MAX_VERTICES], int MST[][MAX_VERTICES], int n)
{
	int* selected = new int[n];
	for (int i = 0; i < n; i++) {
		selected[i] = 0;
		for (int j = 0; j < n; j++) {
			MST[i][j] = INT_MAX;
			if (i == j) {
				MST[i][j] = 0;
			}
		}
	}

	int edge_count = 0;
	selected[0] = 1;
	int min, u, v;
	while (edge_count < (n - 1))
	{
		min = INT_MAX;
		u = 0;
		v = 0;
		for (int i = 0; i < n; i++)
		{
			if (selected[i] == 1) {
				for (int j = 0; j < n; j++)
				{
					if ((selected[j] == 0) && (min > weight_mat[i][j])) {
						min = weight_mat[i][j];
						u = i;
						v = j;
					}
				}
			}
		}
		selected[v] = 1;
		MST[u][v] = weight_mat[u][v];
		MST[v][u] = weight_mat[u][v];
		edge_count = edge_count + 1;
	}
}
#endif
// MST �밢���� 0�̾ƴ϶� INF�� ����. 0�� �����ǹ�?