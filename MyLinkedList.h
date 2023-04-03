#ifndef __MY_LINKED_LIST_H__ //if not define
#define __MY_LINKED_LIST_H__

typedef struct Node { //Node ����ü
	int data; //������ �ʵ�
	struct Node* link;// ���� ����� �ּҸ� ����
}Node;
Node* Create_Node(int newData); //��� ����
void Destroy_Node(Node* node); //��� �Ҹ�
void Append_Node(Node** head, Node* newNode);//��� �߰�
Node* Get_Node(Node* head, int pos); //��� Ž��
void Remove_Node(Node** head, Node* targetNode);//��� ����
void Insert_Node_After(Node* currentNode, Node* newNode); //��� ����
void Print_Linked_List(Node* head); //���Ḯ��Ʈ ��� �Լ�
#endif