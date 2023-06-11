#include "MyGraphMST.h"
#include <limits.h>
int main()
{
	const char* file = "g_file3.txt";
	int weight_mat[MAX_VERTICES][MAX_VERTICES] = { 0 };
	int MST[MAX_VERTICES][MAX_VERTICES] = { 0 };
	int num_of_ver = 7;
	for (int i = 0; i < num_of_ver; i++) { //�׷��� �ʱ�ȭ
		for (int j = 0; j < num_of_ver; j++) {
			if (i != j) {
				weight_mat[i][j] = INT_MAX;
				MST[i][j] = INT_MAX;
			}
		}
	}
	ADJ_Create(file, weight_mat); //����ġ �׷����� ���� ��ķ� ����
	printf("����ġ �׷���: \n");
	ADJ_Print_Array(weight_mat, num_of_ver); //���� ��� ���
	MST_Prim(weight_mat, MST, num_of_ver); //���� �˰����� Ȱ���� MST ����
	printf("MST: \n");
	ADJ_Print_Array(MST, num_of_ver); //MST ��� ���
	return 0;
}