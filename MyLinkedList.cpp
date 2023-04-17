#include <iostream>
#include "MyLinkedList.h"

Node* Create_Node(int newData) { // ��� ���� �Լ�
	Node* newnode = new Node; //newnode �Ҵ�
	(*newnode).data = newData; //�Է¹��� data �Ҵ�
	(*newnode).link = NULL; //link�� NULL

	return newnode;
}

void Append_Node(Node** head, Node* newNode) { // ���� ���� ��� �߰��ϴ� �Լ�
	if (*head == NULL) //*head�� ù ��� �ּ�, Node*�� �ּҶ� Node**. head�� ù ��� �ּҰ��� ������ ���� �ּ�. //head�� ����ִٸ�
	{
		*head = newNode; //ù ��� �ּҿ� newNode �ֱ�
	}
	else
	{
		Node* tail = *head; //head�� NULL�� �ƴ϶��, tail�̶� ��带 ���� tail �ڿ� �� ��� �߰��ϱ� ���� tail �����.
		while ((*tail).link != NULL) // tail�ڰ� NULL�� �ƴ϶��
		{
			tail = (*tail).link; //tail�� link�� ���� ��� ����.
		}
		(*tail).link = newNode; //tail�� link�� NULL�̸�, ���̹Ƿ� link�� newNode ����
	}
}

Node* Merge_List(Node* head_a, Node* head_b) {
	Node* head_c = NULL;
	while (head_a != NULL && head_b != NULL)
	{
		if (head_a->data < head_b->data)
		{
			Append_Node(&head_c, Create_Node(head_a->data));
			head_a = head_a->link;
		}
		else
		{
			Append_Node(&head_c, Create_Node(head_b->data));
			head_b = head_b->link;
		}
	}
	while (head_a != NULL)
	{
		Append_Node(&head_c, Create_Node(head_a->data));
		head_a = head_a->link;
	}
	while (head_b != NULL)
	{
		Append_Node(&head_c, Create_Node(head_b->data));
		head_b = head_b->link;
	}
	return head_c;
}

void Print_Linked_List(Node* head) // ������ ����Ʈ ���
{
	Node* iter = head; // ������ �ݺ��� iter ��� ����.
	int i = 0; // i=0����
	while (iter != NULL) // iter ��尡 NULL�� �� ������
	{
		printf("node[%d]:%d", i, iter->data); // �ݺ��Ǵ� i��° ����� i�� data�� ���.
		iter = iter->link; // iter ��带 ���� ���� �ٲ��ֱ�
		if (iter != NULL) printf(" -> ");
		i++;
	}
	printf("\n");
}