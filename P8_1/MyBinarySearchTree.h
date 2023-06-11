#ifndef __MY_BINARY_SEARCH_TREE_H__
#define __MY_BINARY_SEARCH_TREE_H__
#include <cstdlib>
#include <cstdio>
#include <cmath>
#define MAX(X, Y) (((X)>(Y))? (X) : (Y))
typedef struct BT_Node {
	int data;
	struct BT_Node* left;
	struct BT_Node* right;
}BT_Node;
BT_Node* BST_Create_Node(int newData)
{
	BT_Node* newNode = new BT_Node;
	newNode->data = newData;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
void BST_Destroy_Node(BT_Node* node)
{
	if (node != NULL)
	{
		delete node;
	}
}
//BST ���� �Լ�
int BST_Min(BT_Node* root)
{
	if (root == NULL) exit(1);
	BT_Node* iter = root;
	while (iter->left != NULL)
	{
		iter = iter->left;
	}
	return iter->data;
}
int BST_Max(BT_Node* root)
{
	if (root == NULL) exit(1);
	BT_Node* iter = root;
	while (iter->right != NULL)
	{
		iter = iter->right;
	}
	return iter->data;
}
BT_Node* BST_Search(BT_Node* root, int target)
{
	if (root == NULL) return NULL;
	if (target == root->data) return root;
	if (target < root->data) return BST_Search(root->left, target);
	else return BST_Search(root->right, target);
}
void BST_Insert(BT_Node** root, int key)
{
	BT_Node* newnode = BST_Create_Node(key);
	if (*root == NULL)
	{
		*root = newnode;
	}
	else {
		BT_Node* parent = NULL;
		BT_Node* iter = *root;
		while (iter != NULL)
		{
			parent = iter;
			if (key == iter->data) return; // �ߺ� �� ��� X
			if (key < iter->data) iter = iter->left;
			else iter = iter->right;
		}
		if (key < parent->data) parent->left = newnode;
		else parent->right = newnode;
	}
}
void BST_Delete(BT_Node** root, int key)
{
	BT_Node* vRoot = new BT_Node; // ���� ��� ����
	vRoot->right = *root; // ������ ��带 ��Ʈ ���� ����
	BT_Node* iter = *root; // �ݺ��� (���� ���)
	BT_Node* parent = vRoot; // �θ� ���
	while (iter != NULL && iter->data != key) 
	{
		parent = iter;
		if (key < iter->data) iter = iter->left;
		else iter = iter->right;
	}
	if (iter == NULL) return; // Ű ���� �߰� ���� ����
	BT_Node* delNode = iter; // ������ ��� (delNode)
	// case 1: �ܸ� ��� ����
	if (delNode->left == NULL && delNode->right == NULL) {
		if (parent->left == delNode) parent->left = NULL;
		else parent->right = NULL;
	}
	// case 2: �ϳ��� ���� Ʈ���� ������ ��带 ����
	else if (delNode->left == NULL || delNode->right == NULL) {
		BT_Node* child;
		if (delNode->left == NULL) child = delNode->right;
		else child = delNode->left;
		if (parent->left == delNode) parent->left = child;
		else parent->right = child;
	}
	// case 3: �� ���� ���� Ʈ���� ������ ��带 ����
	else {
		BT_Node* successor = delNode->right;
		BT_Node* pSuccessor = delNode;
		while (successor->left != NULL)
		{
			pSuccessor = successor;
			successor = successor->left;
		}
		delNode->data = successor->data;
		if (pSuccessor->left == successor) pSuccessor->left = successor->right;
		else pSuccessor->right = successor->right;
		delNode = successor;
	}
	if (vRoot->right != *root) *root = vRoot->right;
	BST_Destroy_Node(vRoot);
	BST_Destroy_Node(delNode);
}
//��� ���� �Լ�
void BST_PrintTree2Matrix(int** M, BT_Node* bt_node, int col, int row, int height)
{
	if (bt_node == NULL) return;
	M[row][col] = bt_node->data;
	BST_PrintTree2Matrix(M, bt_node->left, col - pow(2, height - 2), row + 1, height - 1);
	BST_PrintTree2Matrix(M, bt_node->right, col + pow(2, height - 2), row + 1, height - 1);
}
int BST_Height(BT_Node* root)
{
	if (root == NULL)
		return 0;
	return MAX(BST_Height(root->left), BST_Height(root->right)) + 1;
}
void BST_TreePrinter(BT_Node* root)
{
	int h = BST_Height(root);
	int col = (1 << h) - 1;
	int** M = new int* [h];
	for (int i = 0; i < h; i++) {
		M[i] = new int[col];
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < col; j++) {
			M[i][j] = 0;
		}
	}
	for (int j = 0; j < col; j++) {
		printf("==");
	}
	printf("\n");
	BST_PrintTree2Matrix(M, root, col / 2, 0, h);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < col; j++) {
			if (M[i][j] == 0)
			{
				printf("  ");
			}
			else
			{
				printf("%2d", M[i][j]);
			}
		}
		printf("\n");
	}
	for (int j = 0; j < col; j++)
	{
		printf("==");
	}
	printf("\n");
}
#endif