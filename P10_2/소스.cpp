#include "MyGraphSP.h"
#include <limits.h>
int main() {
	const char* file = "g_file4.txt";
	int weight_mat[MAX_VERTICES][MAX_VERTICES] = { 0 };
	int num_of_ver = 7;
	int* path = new int[num_of_ver];
	for (int i = 0; i < num_of_ver; i++) { //�׷��� �ʱ�ȭ
		path[i] = 0;
		for (int j = 0; j < num_of_ver; j++) {
			if (i != j) weight_mat[i][j] = INT_MAX;
		}
	}
	ADJ_Create(file, weight_mat); //����ġ �׷����� ���� ��ķ� ����
	printf("##����ġ �׷���##\n");
	ADJ_Print_Array(weight_mat, num_of_ver); //���� ��� ���
	printf("##�ִ� �Ÿ�##\n");
	Shortest_Path(weight_mat, num_of_ver, 0, path); //�ִܰŸ� ���
	printf("\n##�ִ� �Ÿ� ���##\n");
	for (int i = 0; i < num_of_ver; i++) {
		PrintPath(path, 0, i); //���� ����0���� ��� ���� ������ �ִܰŸ� ���
		printf("\n");
	}
	return 0;
}