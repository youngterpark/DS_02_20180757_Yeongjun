#ifndef __MY_GRAPH_LL_H__
#define __MY_GRAPH_LL_H__
#include <stdio.h>
#include "MyArrayStack.hpp"
#define MAX_VERTICES 100
typedef struct G_Node { //Node ����ü
	int vertex; //������ �ʵ�
	struct G_Node* link; // ���� ����� �ּҸ� ����
}G_Node;
//0) ���Ͽ� ����� �����ͷ� �׷��� ����
void ADJ_Create(const char* g_file, int adj_mat[][MAX_VERTICES]);
//1) ������ ���� ���
void ADJ_Degree(int adj_mat[][MAX_VERTICES], int n);
//2) ���� ��� �� ���� ����Ʈ ��ȯ
void ADJ_Insert(G_Node** List, int i, int j);
void ADJ_Mat2List(int adj_mat[][MAX_VERTICES], int n, G_Node** List);
//3) ���� �켱 Ž��
void Graph_DFS(G_Node** List, int v);
void Graph_DFS_Recursive(G_Node** List, int v);
//����Լ� ����
void ADJ_Print_Array(int adj_mat[][MAX_VERTICES], int n);
void ADJ_Print_List(G_Node** List, int n);
#endif