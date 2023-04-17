#include <iostream>
#include "MyDoublyLinkedList.h"
using namespace std;

// remove 0�̶� 2�� �׽�Ʈ �غ���
int main(void) {
	Node* head = NULL;
	DLL_Append_Node(&head, DLL_Create_Node(15)); // ����� 15��� ����
	DLL_Append_Node(&head, DLL_Create_Node(31)); // 31 ��� ����
	DLL_Print_Linked_List(head); // ��� ��� (15, 31)
	//DLL_Get_Node() �Լ� ��� �׽�Ʈ
	Node* temp = DLL_Get_Node(head, 0); // 15��� get test
	printf("Get_Node() test: %d\n", temp->data); // Ȯ�� ���
	//Insert_Node_After() �Լ� ��� �׽�Ʈ
	DLL_Insert_Node_After(DLL_Get_Node(head, 0), DLL_Create_Node(25)); // get�� 15��� �ڿ� 25 ��� ����
	DLL_Print_Linked_List(head); // ��� ��� (15, 25, 31)
	//Remove_Node() �Լ� ��� �׽�Ʈ
	DLL_Remove_Node(&head, DLL_Get_Node(head, 0)); // 15 ��� ����
	DLL_Append_Node(&head, DLL_Create_Node(41)); // 41 ��� ����
	DLL_Print_Linked_List(head); // ��� ��� (25, 31, 41)
	DLL_Print_Linked_List_Reverse(DLL_Get_Node(head, 2)); // ��� ������ ��� (41, 31, 25)

	printf("\n");
	return 0;
}

// 4.3 ����
