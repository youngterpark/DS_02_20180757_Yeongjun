#ifndef __MY_LINKED_LIST_H__ //if not define
#define __MY_LINKED_LIST_H__

typedef struct Node { //Node ����ü
	int data; //������ �ʵ�
	struct Node* link;// ���� ����� �ּҸ� ����
}Node;
Node* Create_Node(int newData); //��� ����
void Destroy_Node(Node* node); //��� �Ҹ�
void Append_Node(Node** head, Node* newNode);//��� �߰�
void Append_Node_T(Node** tail, Node* newNode); // Tail ��� ��� �߰�
void Print_Circular_Linked_List(Node* head); //���� ���Ḯ��Ʈ ��� �Լ�
void Print_Circular_Linked_List_T(Node* tail); // Tail ��� ���� ���Ḯ��Ʈ ��� �Լ�
#endif