#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int key;
	struct Node* Lnode; // 작은 값
	struct Node* Rnode; // 큰 값
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
		printf("중복!!\n");
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
	// 삭제하고자 할 노드의 자식이 없는 경우
	// 1) '6' 삭제하고자 하는 노드의 current parrent가 있을 것. parrent 기준으로 삭제하고자 할 노드가 왼쪽인지 오른쪽인지 판단.
	// 삭제하는 법 : 연결고리 끊어주면 됨.(=NULL값으로 없애줘버리기) 후 cur을 free로.
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
	// 삭제하고자 할 노드의 자식이 하나인 경우
	// 2) '8' 삭제. 부모 기준 왼쪽 삭제인지 오른쪽 삭제인지 판단 먼저.
	// cur갖고 있는 노드(child)가 왼쪽자식인지 오른쪽자식인지(왼쪽 NULL이 아니면, 이런식으로 판별) 해서 child 지정.
	// par랑 child 연결. 후 cureent 날림
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
	// 삭제하고자 할 노드의 자식이 둘인 경우
	// 3) '15' 삭제. 15는 왼쪽보다 커야하고 오른쪽보다 작아야 함. (왼쪽의 가장오른쪽, 오른쪽의 가장 왼쪽)
	// '18'을 temp, 왼쪽 자식노드가 없을 때 까지 while. 그럼 temp가 '16'을 가리킴, par은 '18'
	// 오른쪽의 가장 왼쪽 노드가 오른쪽자식 노드를 갖고 있을 때 주의.
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
	// 삭제하고자 할 값이 없는 경우
	if (tree->current == NULL)
	{
		return;
	}

	// 삭제하고자 할 노드의 자식이 없는 경우
	if (tree->current->Lnode == NULL && tree->current->Rnode == NULL)
	{
		Ch_No(tree);
		return;
	}
	// 삭제하고자 할 노드의 자식이 하나인 경우
	else if (tree->current->Lnode == NULL || tree->current->Rnode == NULL)
	{
		Ch_One(tree);
		return;
	}
	// 삭제하고자 할 노드의 자식이 둘인 경우
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
	Delete(&tree, 10); // 다 지워 봐야 함.

	Display(tree.Root);



}