//�ǽ�����4.1_1 + 4.1_2

#include <iostream>
#include "MyLinkedList.h"
using namespace std;

int main(void) {
	// 4.1.1
	//Node* head = NULL; //head��� NULL
	//
	//// ���� ���Ḯ��Ʈ ����
	//Append_Node(&head, Create_Node(15));
	//Append_Node(&head, Create_Node(25));
	//Append_Node(&head, Create_Node(31));
	//Append_Node(&head, Create_Node(24));
	//// ���� ���Ḯ��Ʈ ���
	//Print_Circular_Linked_List(head);

	// 4.1.2
	Node* tail = NULL;

	// ���� ���Ḯ��Ʈ ����
	Append_Node_T(&tail, Create_Node(15));
	Append_Node_T(&tail, Create_Node(25));
	Append_Node_T(&tail, Create_Node(31));
	Append_Node_T(&tail, Create_Node(24));
	// ���� ���Ḯ��Ʈ ���
	Print_Circular_Linked_List_T(tail);


	return 0;
}














// ����
