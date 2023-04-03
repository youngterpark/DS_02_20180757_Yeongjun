#include <iostream>
#include "MyLinkedList.h"

Node* Create_Node(int newData) {
	// 3-1
	//Node* newnode = (Node*)malloc(sizeof(Node));
	Node* newnode = new Node;
	(*newnode).data = newData;
	(*newnode).link = NULL;

	return newnode;
}

void Destroy_Node(Node* node) {
	// 3-1
	if (node != NULL)
	{
		delete node;
	}
}

void Append_Node(Node** head, Node* newNode) {
	// 3-1
	if (*head == NULL) //*head�� ù ��� �ּ�, Node*�� �ּҶ� Node**.
	{
		*head = newNode;
	}
	else
	{
		Node* tail = *head; 
		while ((*tail).link != NULL)
		{
			tail = (*tail).link;
		}
		(*tail).link = newNode;
	}
}

Node* Get_Node(Node* head, int pos)//��� Ž��, (head ���=ù ����� �ּҸ� ����Ŵ, ã�� ���� ��� ���� �ƴ϶� ��ġ��) pos��° ��� Get�ϴ� �Լ�
{
	Node* iter = head;
	int i = 0;
	while (pos != i)
	{
		iter = (*iter).link;
		i++;
	}
	return iter; 
}

void Remove_Node(Node** head, Node* targetNode) //��� ����
{
	// ������ �����ְ� ������ �ؾ� ��.
	Node* cur = *head;
	Node* bef = *head; // ù ��带 ������ ���� ���� ó����.
	while (cur != NULL)
	{
		if (cur->data == targetNode->data)
		{
			if (cur == *head)
			{
				*head = (*head)->link;
			}
			else
			{
				bef->link = cur->link;
				Destroy_Node(cur);
				return;
			}
		}
		else
		{
			bef = cur;
			cur = cur->link;
		}
	}
}

void Insert_Node_After(Node* currentNode, Node* newNode) //��� ����
{
	// <25��带 15��� �ڿ� ����>
	// 15 ��� �ּ� ���� ȹ��
	if (currentNode->link != NULL)
	{
		newNode->link = currentNode->link;
		currentNode->link = newNode;
	}
	else
	{
		currentNode->link = newNode;
	}

	
	// 25 ��� ����
	
	// 25����� link�� 15����� link�� ������Ʈ
	// 15����� link�� 27����� �ּҷ� ������Ʈ
}

void Print_Linked_List(Node* head)
{
	Node* iter = head;
	int i = 0;
	while (iter != NULL)
	{
		printf("node[%d]:%d", i, iter->data); //iter->data == (*iter).data
		iter = iter->link;
		if (iter != NULL) printf(" -> ");
		i++;
	}
	printf("\n");
}