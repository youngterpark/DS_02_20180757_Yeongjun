#include <iostream>
#include "MyDoublyLinkedList.h"

Node* DLL_Create_Node(int newData) // ��� ����
{
	Node* newnode = new Node; //newnode �Ҵ�
	newnode->data = newData; //�Է¹��� data �Ҵ�
	newnode->prev = NULL; //prev NULL
	newnode->next = NULL; //next NULL
	return newnode;
}
void DLL_Destroy_Node(Node* node) // ��� �Ҹ�
{
	if (node != NULL) //node�� NULL�� �ƴϸ�
	{
		delete node; //��� �Ҹ�
	}
}
void DLL_Append_Node(Node** head, Node* newnode) // ��� �߰�
{
	if ((*head) == NULL) //���� ��尡 ���������, ���ο� ��带 ���� ����
	{
		*head = newnode; //����� = newNode
	}
	else // ������ ��� Ž��
	{
		Node* tail = *head; //tail=����� �� �ʱ�ȭ
		while (tail->next != NULL) //tail.next�� NULL�� �ƴϸ� �ݺ�
		{
			tail = tail->next; //tail�� next�� �ݺ��ϸ� ������ ��� Ž��
		}
		tail->next = newnode; //tail.next�� NULL�̸� ������ ���. next�� newnode ����
		newnode->prev = tail; //DLL�� �°� prev�� ���� tail ����
	}
}
Node* DLL_Get_Node(Node* head, int pos) // ��� Ž��
{
	Node* iter = head; // ã�� ���� ��尡 ���ö����� ���� iter ��忡 ù ��� �ֱ�.
	int i = 0; // Ž�� �� ���� 1�� Ŀ���� i
	while (pos != i) // i�� ã����� ��ġ pos�� �������� �ݺ��� ����
	{
		iter = iter->next; // iter�� iter�� link ���� �ٲٸ鼭 ���� ��� Ž��
		i++;
	}
	return iter; // ã�� ���� ��ġ�� ��� ��ȯ
}
void DLL_Remove_Node(Node** head, Node* targetNode) // ��� ����
{
	if (targetNode->prev == NULL) // ����� ����
	{
		*head = (*head)->next; // ����� �ٲ��ְ�
		if (*head != NULL) // ��尡 ����� �ϳ��� ������, head ��� next�� NULL �̹Ƿ�
		(*head)->prev = NULL;
		DLL_Destroy_Node(targetNode);
		return;
	}
	
	else
	{
		targetNode->prev->next = targetNode->next;
		if (targetNode->next == NULL)
		{
			DLL_Destroy_Node(targetNode);
			return;
		}
		else
		{
			targetNode->next->prev = targetNode->prev;
			DLL_Destroy_Node(targetNode);
			return;
		}
	}
}
void DLL_Insert_Node_After(Node* currentNode, Node* newNode) // ��� ����
{
	if (currentNode->next != NULL) 
	{
		newNode->next = currentNode->next; 
		currentNode->next->prev = newNode;
		newNode->prev = currentNode;
		currentNode->next = newNode;
	}
	else 
	{
		currentNode->next = newNode;
	}
}
void DLL_Print_Linked_List(Node* head) // ���� ���Ḯ��Ʈ ���
{
	Node* iter = head;
	int i = 0;
	while (iter != NULL)
	{
		printf("N[%d]:%d", i, iter->data);
		iter = iter->next;
		if (iter != NULL) printf(" <-> ");
		i++;
	}
	printf("\n");
}
void DLL_Print_Linked_List_Reverse(Node* tail) // ���� ���Ḯ��Ʈ ���� ���
{
	Node* iter = tail;
	int i = 0;
	while (iter != NULL)
	{
		printf("N[%d]:%d", i, iter->data);
		iter = iter->prev;
		if (iter != NULL) printf(" <-> ");
		i++;
	}
	printf("\n");
}