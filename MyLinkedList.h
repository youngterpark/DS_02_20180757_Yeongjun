#ifndef __MY_LINKED_LIST_H__ //if not define
#define __MY_LINKED_LIST_H__

typedef struct Node { //Node ����ü
	int data; //������ �ʵ�
	struct Node* link;// ���� ����� �ּҸ� ����
}Node;
Node* Create_Node(int newData); //��� ���� �Լ�
void Append_Node(Node** head, Node* newNode);//��� �߰� �Լ�
Node* Merge_List(Node* head_a, Node* head_b); // �� ���Ḯ��Ʈ �պ� �Լ�
void Print_Linked_List(Node* head); //���Ḯ��Ʈ ��� �Լ�
#endif