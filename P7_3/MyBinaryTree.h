#ifndef __MY_BINARY_TREE_H__
#define __MY_BINARY_TREE_H__
#include <cstdlib>
#include <cstdio>
#include <cmath>
#define MAX(X, Y) (((X)>(Y))? (X) : (Y))
typedef struct BT_Node {
	int data;
	struct BT_Node* left;
	struct BT_Node* right;
}BT_Node;
BT_Node* BT_Create_Node(int newData)
{
	BT_Node* newNode = new BT_Node;
	newNode->data = newData;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
void BT_Destroy_Node(BT_Node* node)
{
	if (node != NULL)
	{
		delete node;
	}
}
void BT_Make_Left_Sub_Tree(BT_Node* parent, BT_Node* sub)
{
	if (parent->left != NULL)
	{
		BT_Destroy_Node(parent->left);
	}
	parent->left = sub;
}
void BT_Make_Right_Sub_Tree(BT_Node* parent, BT_Node* sub)
{
	if (parent->right != NULL)
	{
		BT_Destroy_Node(parent->right);
	}
	parent->right = sub;
}
void BT_Preorder_Traversal(BT_Node* node)
{
	if (node != NULL)
	{
		printf("%2d ",node->data);
		BT_Preorder_Traversal(node->left);
		BT_Preorder_Traversal(node->right);
	}
}
void BT_Inorder_Traversal(BT_Node* node)
{
	if (node != NULL)
	{
		BT_Inorder_Traversal(node->left);
		printf("%2d ", node->data);
		BT_Inorder_Traversal(node->right);
	}
}
void BT_Postorder_Traversal(BT_Node* node)
{
	if (node != NULL)
	{
		BT_Postorder_Traversal(node->left);
		BT_Postorder_Traversal(node->right);
		printf("%2d ", node->data);
	}
}
void BT_Count_Node(BT_Node* node, int* count)
{
	if (node != NULL)
	{
		*count = *count + 1;
		BT_Count_Node(node->left, count); // 파라미터 입력 수정
		BT_Count_Node(node->right, count);
	}
}
void BT_Count_Leaf(BT_Node* node, int* count)
{
	if (node != NULL)
	{
		BT_Count_Leaf(node->left, count);
		if (node->left == NULL && node->right == NULL)
		{
			*count = *count + 1;
		}
		BT_Count_Leaf(node->right, count);
	}
}
void BT_PrintTree2Matrix(int** M, BT_Node* bt_node, int col, int row, int height)
{
	if (bt_node == NULL) return;
	M[row][col] = bt_node->data;
	BT_PrintTree2Matrix(M, bt_node->left, col - pow(2, height - 2), row + 1, height - 1);
	BT_PrintTree2Matrix(M, bt_node->right, col + pow(2, height - 2), row + 1, height - 1);
}
int BT_Height(BT_Node* root) {
	if (root == NULL)
		return 0;
	return MAX(BT_Height(root->left), BT_Height(root->right)) + 1;
}
void BT_TreePrinter(BT_Node* root)
{
	int h = BT_Height(root);
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
	BT_PrintTree2Matrix(M, root, col / 2, 0, h);
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
#endif // !__MY_BINARY_TREE_H__
