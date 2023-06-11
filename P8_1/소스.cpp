#include "MyBinarySearchTree.h"
int main() {
	BT_Node* root = NULL;
	//���� Ž�� Ʈ�� ����
	BST_Insert(&root, 50);
	BST_Insert(&root, 35);
	BST_Insert(&root, 70);
	BST_Insert(&root, 6);
	BST_Insert(&root, 40);
	BST_Insert(&root, 36);
	BST_Insert(&root, 45);
	BST_Insert(&root, 38);
	BST_Insert(&root, 37);
	BST_TreePrinter(root);
	//�⺻ ���� ��� �׽�Ʈ
	printf("Min value: %d \n", BST_Min(root));
	printf("Max value: %d \n", BST_Max(root));
	printf("Search 36 node: %d \n", BST_Search(root, 36)->data);
	//���� �׽�Ʈ
	BST_Delete(&root, 35); //35, 38, 6, 50 ��� ���� �׽�Ʈ ����
	BST_Insert(&root, 39);
	BST_TreePrinter(root);
	return 0;
}