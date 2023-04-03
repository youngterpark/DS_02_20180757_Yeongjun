#include <iostream>
#include "MyLinkedList.h"

Node* Create_Node(int newData) {
	// 3-1
	//Node* newnode = (Node*)malloc(sizeof(Node));
	Node* newnode = new Node;
	(*newnode).data = newData;
	(*newnode).link = NULL;

	return newnode;
}

void Destroy_Node(Node* node) {
	// 3-1
	if (node != NULL)
	{
		delete node;
	}
}

void Append_Node(Node** head, Node* newNode) {
	// 3-1
	if (*head == NULL) //*head는 첫 노드 주소, Node*의 주소라서 Node**.
	{
		*head = newNode;
	}
	else
	{
		Node* tail = *head; 
		while ((*tail).link != NULL)
		{
			tail = (*tail).link;
		}
		(*tail).link = newNode;
	}
}

Node* Get_Node(Node* head, int pos)//노드 탐색, (head 노드=첫 노드의 주소를 가리킴, 찾고 싶은 노드 값이 아니라 위치네) pos번째 노드 Get하는 함수
{
	Node* iter = head;
	int i = 0;
	while (pos != i)
	{
		iter = (*iter).link;
		i++;
	}
	return iter; 
}

void Remove_Node(Node** head, Node* targetNode) //노드 삭제
{
	// 연결을 시켜주고 삭제를 해야 함.
	Node* cur = *head;
	Node* bef = *head; // 첫 노드를 삭제할 때는 따로 처리함.
	while (cur != NULL)
	{
		if (cur->data == targetNode->data)
		{
			if (cur == *head)
			{
				*head = (*head)->link;
			}
			else
			{
				bef->link = cur->link;
				Destroy_Node(cur);
				return;
			}
		}
		else
		{
			bef = cur;
			cur = cur->link;
		}
	}
}

void Insert_Node_After(Node* currentNode, Node* newNode) //노드 삽입
{
	// <25노드를 15노드 뒤에 삽입>
	// 15 노드 주소 정보 획득
	if (currentNode->link != NULL)
	{
		newNode->link = currentNode->link;
		currentNode->link = newNode;
	}
	else
	{
		currentNode->link = newNode;
	}

	
	// 25 노드 생성
	
	// 25노드의 link를 15노드의 link로 업데이트
	// 15노드의 link를 27노드의 주소로 업데이트
}

void Print_Linked_List(Node* head)
{
	Node* iter = head;
	int i = 0;
	while (iter != NULL)
	{
		printf("node[%d]:%d", i, iter->data); //iter->data == (*iter).data
		iter = iter->link;
		if (iter != NULL) printf(" -> ");
		i++;
	}
	printf("\n");
}
