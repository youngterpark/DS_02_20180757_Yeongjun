#include <iostream>
#include "MyLinkedList.h"

Node* Create_Node(int newData) { // ��� ���� �Լ�
	// 3-1
	//Node* newnode = (Node*)malloc(sizeof(Node));
	Node* newnode = new Node; //newnode �Ҵ�
	(*newnode).data = newData; //�Է¹��� data �Ҵ�
	(*newnode).link = NULL; //link�� NULL

	return newnode;
}

void Destroy_Node(Node* node) { // ��� �Ҹ� �Լ�
	// 3-1
	if (node != NULL) // node�� NULL�� �ƴϸ�(���� ����)
	{
		delete node; // ��� �Ҹ�
	}
}

void Append_Node(Node** head, Node* newNode) { // ���� ���� ��� �߰��ϴ� �Լ�
	// 3-1
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

Node* Reverse_List(Node* head) // �� ���Ḯ��Ʈ ���
{
	// �� ���Ḯ��Ʈ ����� ���� ������ ��� �ּ� ����
	Node* p = head; // ����, p <- ���� ���Ḯ��Ʈ ����
	Node* q = NULL; // ���߿� �� ���Ḯ��Ʈ ����� ����ϴ� ����
	Node* r; // �ױ� �� ������ ����
	while (p != NULL)
	{
		r = q; // ���� �޾ƿ� �׾Ƴ��� ���� ���Ƿ� �����ϴ� ����
		q = p; // ��� ������ ���Ḯ��Ʈ �� �� ��带 q�� ����
		p = p->link; // �� �� ��� ������Ʈ
		q->link = r; // q�� �ִ� ��� ������ ��� �ڿ� ������ �ִ� ���� �ױ�
	}

	return q; // �� ���Ḯ��Ʈ ���
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