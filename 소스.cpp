// �ǽ����� 3.3
//// �־��� ���Ḯ��Ʈ�� �� ���Ḯ��Ʈ�� �����ϴ� �Լ��� �����غ���
#include <iostream>
#include "MyLinkedList.h"
using namespace std;

int main(void) {
	Node* head = NULL; //head��� NULL

	// �⺻ ��� ����
	Append_Node(&head, Create_Node(15)); //15��� ���� �� �߰�
	Append_Node(&head, Create_Node(25)); //25��� ���� �� �߰�
	Append_Node(&head, Create_Node(31)); //31��� ���� �� �߰�
	Append_Node(&head, Create_Node(24)); //24��� ���� �� �߰�
	Print_Linked_List(head); // �⺻ ���Ḯ��Ʈ ��ü ���

	// Reverse_List
	Node* reverse = Reverse_List(head);
	Print_Linked_List(reverse); // �� ���Ḯ��Ʈ ��ü ���
	printf("\n");
	return 0;
}

// ����
