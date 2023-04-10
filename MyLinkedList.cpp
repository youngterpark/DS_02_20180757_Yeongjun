#include <iostream>
#include "MyLinkedList.h"

Node* Create_Node(int newData) { // ��� ���� �Լ�
	Node* newnode = new Node; //newnode �Ҵ�
	(*newnode).data = newData; //�Է¹��� data �Ҵ�
	(*newnode).link = NULL; //link�� NULL

	return newnode;
}

void Destroy_Node(Node* node) { // ��� �Ҹ� �Լ�
	if (node != NULL) // node�� NULL�� �ƴϸ�(���� ����)
	{
		delete node; // ��� �Ҹ�
	}
}

void Append_Node(Node** head, Node* newNode) { //��� �߰�
	Node* tail;
	if ((*head) == NULL) // ���� ��尡 ���������, ���ο� ��带 ���� ����
	{
		*head = newNode;
		newNode->link = newNode;
	}
	else
	{
		tail = *head;
		do
		{
			tail = tail->link;
		} while (tail->link != *head);
		tail->link = newNode;
		newNode->link = *head;
	}
}

void Append_Node_T(Node** tail, Node* newNode) { //Tail ��� ��� �߰�
	if ((*tail) == NULL)
	{
		*tail = newNode;
		newNode->link = newNode;
	}
	else
	{
		newNode->link = (*tail)->link;
		(*tail)->link = newNode;
		*tail = newNode;
	}
}

void Print_Circular_Linked_List(Node* head) { // ���� ���Ḯ��Ʈ ���
	if (head == NULL) return; //��尡 ���������, �Լ� ����
	Node* iter = head;
	int i = 0;
	do
	{
		printf("node[%d]:%d", i, iter->data);
		iter = iter->link;
		if (iter != NULL) printf(" -> ");
		i++;
	} while (iter != head); //���� ���ƿ� ������ �ݺ�
	printf("head:%d", iter->data); //������ ��尡 ���� ����Ǿ����� Ȯ��
	printf("\n");
}
void Print_Circular_Linked_List_T(Node* tail) { // Tail ��� ���� ���Ḯ��Ʈ ��� �Լ�
	Node* head = tail->link;
	if (head == NULL) return; //��尡 ���������, �Լ� ����
	Node* iter = head;
	int i = 0;
	do
	{
		printf("node[%d]:%d", i, iter->data);
		iter = iter->link;
		if (iter != NULL) printf(" -> ");
		i++;
	} while (iter != head); //���� ���ƿ� ������ �ݺ�
	printf("head:%d", iter->data); //������ ��尡 ���� ����Ǿ����� Ȯ��
	printf("\n");
}