#ifndef __MYDOUbLY_LINKED_LIST_H__
#define __MYDOUbLY_LINKED_LIST_H__
typedef struct Node { // Node ����ü
	int data; // ������ �ʵ�
	struct Node* prev; // ���� ����� �ּҸ� ����
	struct Node* next; // ���� ����� �ּҸ� ����
}Node;
Node* DLL_Create_Node(int newData); // ��� ����
void DLL_Destroy_Node(Node* node); // ��� �Ҹ�
void DLL_Append_Node(Node** head, Node* newnode); // ��� �߰�
Node* DLL_Get_Node(Node* head, int pos); // ��� Ž��
void DLL_Remove_Node(Node** head, Node* targetNode); // ��� ����
void DLL_Insert_Node_After(Node* currentNode, Node* newNode); // ��� ����
void DLL_Print_Linked_List(Node* head); // ���� ���Ḯ��Ʈ ���
void DLL_Print_Linked_List_Reverse(Node* tail); // ���� ���Ḯ��Ʈ ���� ���
#endif