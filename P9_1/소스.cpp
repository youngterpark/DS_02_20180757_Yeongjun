#include "MyGraphLL.h"
int main()
{
	const char* file = "g_file.txt";
	int adj_mat[MAX_VERTICES][MAX_VERTICES] = { 0 };
	int num_of_ver = 7;
	G_Node** List = new G_Node * [num_of_ver]; //���� ����Ʈ ��� ������ �迭 ����
	for (int i = 0; i < num_of_ver; i++) List[i] = NULL; //NULL�� �ʱ�ȭ
	ADJ_Create(file, adj_mat); //0) �׷����� ���� ��ķ� ����
	ADJ_Print_Array(adj_mat, num_of_ver); //���� ��� ���
	ADJ_Degree(adj_mat, num_of_ver); //1) �׷����� �� ������ ���� ���
	ADJ_Mat2List(adj_mat, num_of_ver, List); //2) ���� ��� �� ���� ����Ʈ�� ��ȯ
	ADJ_Print_List(List, num_of_ver); //���� ����Ʈ ���
	Graph_DFS(List, 1); //3) ���� �켱 Ž�� (�ݺ���) 1 4 6 5 3 2 0
	printf("\n");
	Graph_DFS_Recursive(List, 1); //3) ���� �켱 Ž�� (��͹�)
	delete[] List;
	return 0;
}
