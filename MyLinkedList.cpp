#include <iostream>
#include "MyLinkedList.h"

Node* Create_Node(int newData) { // 노드 생성 함수
	Node* newnode = new Node; //newnode 할당
	(*newnode).data = newData; //입력받은 data 할당
	(*newnode).link = NULL; //link는 NULL

	return newnode;
}

void Destroy_Node(Node* node) { // 노드 소멸 함수
	if (node != NULL) // node가 NULL이 아니면(에러 때문)
	{
		delete node; // 노드 소멸
	}
}

void Append_Node(Node** head, Node* newNode) { //노드 추가
	Node* tail;
	if ((*head) == NULL) // 현재 헤드가 비어있으면, 새로운 노드를 헤드로 설정
	{
		*head = newNode;
		newNode->link = newNode;
	}
	else
	{
		tail = *head;
		do
		{
			tail = tail->link;
		} while (tail->link != *head);
		tail->link = newNode;
		newNode->link = *head;
	}
}

void Append_Node_T(Node** tail, Node* newNode) { //Tail 기반 노드 추가
	if ((*tail) == NULL)
	{
		*tail = newNode;
		newNode->link = newNode;
	}
	else
	{
		newNode->link = (*tail)->link;
		(*tail)->link = newNode;
		*tail = newNode;
	}
}

void Print_Circular_Linked_List(Node* head) { // 원형 연결리스트 출력
	if (head == NULL) return; //헤드가 비어있으면, 함수 종료
	Node* iter = head;
	int i = 0;
	do
	{
		printf("node[%d]:%d", i, iter->data);
		iter = iter->link;
		if (iter != NULL) printf(" -> ");
		i++;
	} while (iter != head); //헤드로 돌아올 때까지 반복
	printf("head:%d", iter->data); //마지막 노드가 헤드로 연결되었는지 확인
	printf("\n");
}
void Print_Circular_Linked_List_T(Node* tail) { // Tail 기반 원형 연결리스트 출력 함수
	Node* head = tail->link;
	if (head == NULL) return; //헤드가 비어있으면, 함수 종료
	Node* iter = head;
	int i = 0;
	do
	{
		printf("node[%d]:%d", i, iter->data);
		iter = iter->link;
		if (iter != NULL) printf(" -> ");
		i++;
	} while (iter != head); //헤드로 돌아올 때까지 반복
	printf("head:%d", iter->data); //마지막 노드가 헤드로 연결되었는지 확인
	printf("\n");
}