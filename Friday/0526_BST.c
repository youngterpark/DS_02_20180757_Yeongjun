#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int key;
	struct Node* Lnode; // ���� ��
	struct Node* Rnode; // ū ��
}Node;

typedef struct Tree
{
	Node* Root;
	Node* current;
	Node* parrent;
	Node* child;
}Tree;

int Search(Tree* tree,int data)
{
	tree->current = tree->Root;
	tree->parrent = NULL;

	while (1)
	{
		if (tree->current->key == data)
		{
			return 1;
		}
		else if (tree->current->key < data)
		{
			tree->parrent = tree->current;
			if (tree->current->Rnode == NULL)
			{
				return 0;
			}
			tree->current = tree->current->Rnode;
		}
		else if (tree->current->key > data)
		{
			tree->parrent = tree->current;
			if (tree->current->Lnode == NULL)
			{
				return 0;
			}
			tree->current = tree->current->Lnode;
		}
	}
}

void Insert(Tree* tree, int data)
{
	Node* newnode = malloc(sizeof(Node));
	newnode->key = data;
	newnode->Lnode = NULL;
	newnode->Rnode = NULL;

	if (tree->Root == NULL)
	{
		tree->Root = newnode;
		return;
	}

	if (Search(tree, data))
	{
		printf("�ߺ�!!\n");
		return;
	}
	else
	{
		if (tree->parrent->key < data)
		{
			tree->parrent->Rnode = newnode;
		}
		else
		{
			tree->parrent->Lnode = newnode;

		}
	}

}

void Display(Node* root)
{
	if (root != NULL)
	{
		Display(root->Lnode);
		printf("%d -> ", root->key);
		Display(root->Rnode);
	}
}
void Ch_No(Tree* tree)
{
	// �����ϰ��� �� ����� �ڽ��� ���� ���
	// 1) '6' �����ϰ��� �ϴ� ����� current parrent�� ���� ��. parrent �������� �����ϰ��� �� ��尡 �������� ���������� �Ǵ�.
	// �����ϴ� �� : ����� �����ָ� ��.(=NULL������ �����������) �� cur�� free��.
	if (tree->current == tree->parrent->Lnode)
	{
		tree->parrent->Lnode = NULL;
	}
	else
	{
		tree->parrent->Rnode = NULL;
	}
	free(tree->current);
}

void Ch_One(Tree* tree)
{
	// �����ϰ��� �� ����� �ڽ��� �ϳ��� ���
	// 2) '8' ����. �θ� ���� ���� �������� ������ �������� �Ǵ� ����.
	// cur���� �ִ� ���(child)�� �����ڽ����� �������ڽ�����(���� NULL�� �ƴϸ�, �̷������� �Ǻ�) �ؼ� child ����.
	// par�� child ����. �� cureent ����
	if (tree->current == tree->parrent->Lnode)
	{
		if (tree->current->Rnode == NULL)
		{
			tree->parrent->Lnode = tree->current->Lnode;
		}
		else
		{
			tree->parrent->Lnode = tree->current->Rnode;
		}
		free(tree->current);
	}
	else
	{
		if (tree->current->Rnode == NULL)
		{
			tree->parrent->Rnode = tree->current->Lnode;
		}
		else
		{
			tree->parrent->Rnode = tree->current->Rnode;
		}
		free(tree->current);
	}
}

void Ch_Two(Tree* tree)
{
	// �����ϰ��� �� ����� �ڽ��� ���� ���
	// 3) '15' ����. 15�� ���ʺ��� Ŀ���ϰ� �����ʺ��� �۾ƾ� ��. (������ ���������, �������� ���� ����)
	// '18'�� temp, ���� �ڽĳ�尡 ���� �� ���� while. �׷� temp�� '16'�� ����Ŵ, par�� '18'
	// �������� ���� ���� ��尡 �������ڽ� ��带 ���� ���� �� ����.
	Node* temp = tree->current->Rnode;
	Node* par = tree->current;
	Node* prev = NULL;

	while (temp->Lnode != NULL)
	{
		prev = par;
		par = temp;
		temp = temp->Lnode;
	}

	tree->current->key = temp->key;

	if (prev != NULL)
	{
		prev->Lnode = temp->Rnode;
	}
	else
	{
		par->Rnode = temp->Rnode;
	}
	free(temp);
}

void Delete(Tree* tree, int data)
{
	Search(tree, data);
	// �����ϰ��� �� ���� ���� ���
	if (tree->current == NULL)
	{
		return;
	}

	// �����ϰ��� �� ����� �ڽ��� ���� ���
	if (tree->current->Lnode == NULL && tree->current->Rnode == NULL)
	{
		Ch_No(tree);
		return;
	}
	// �����ϰ��� �� ����� �ڽ��� �ϳ��� ���
	else if (tree->current->Lnode == NULL || tree->current->Rnode == NULL)
	{
		Ch_One(tree);
		return;
	}
	// �����ϰ��� �� ����� �ڽ��� ���� ���
	else if (tree->current->Lnode != NULL && tree->current->Rnode != NULL)
	{
		Ch_Two(tree);
		return;
	}
}

void main()
{
	Tree tree;
	tree.Root = NULL;
	tree.current = NULL;
	tree.parrent = NULL;
	tree.child = NULL;

	Insert(&tree, 15);
	Insert(&tree, 18);
	Insert(&tree, 10);
	Insert(&tree, 11);
	Insert(&tree, 8);
	Insert(&tree, 19);
	Insert(&tree, 16);
	Insert(&tree, 3);
	Insert(&tree, 9);

	Display(tree.Root);
	printf("\n\n");
	Delete(&tree, 10); // �� ���� ���� ��.

	Display(tree.Root);



}