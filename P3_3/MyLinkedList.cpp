#include <iostream>
#include "MyLinkedList.h"

Node* Create_Node(int newData) { // 노드 생성 함수
	// 3-1
	//Node* newnode = (Node*)malloc(sizeof(Node));
	Node* newnode = new Node; //newnode 할당
	(*newnode).data = newData; //입력받은 data 할당
	(*newnode).link = NULL; //link는 NULL

	return newnode;
}

void Destroy_Node(Node* node) { // 노드 소멸 함수
	// 3-1
	if (node != NULL) // node가 NULL이 아니면(에러 때문)
	{
		delete node; // 노드 소멸
	}
}

void Append_Node(Node** head, Node* newNode) { // 제일 끝에 노드 추가하는 함수
	// 3-1
	if (*head == NULL) //*head는 첫 노드 주소, Node*의 주소라서 Node**. head는 첫 노드 주소값을 저장한 값의 주소. //head가 비어있다면
	{
		*head = newNode; //첫 노드 주소에 newNode 넣기
	}
	else
	{
		Node* tail = *head; //head가 NULL이 아니라면, tail이란 노드를 만들어서 tail 뒤에 새 노드 추가하기 위해 tail 만들기.
		while ((*tail).link != NULL) // tail뒤가 NULL이 아니라면
		{
			tail = (*tail).link; //tail의 link를 따라 계속 추적.
		}
		(*tail).link = newNode; //tail의 link가 NULL이면, 끝이므로 link에 newNode 생성
	}
}

Node* Reverse_List(Node* head) // 역 연결리스트 출력
{
	// 역 연결리스트 출력을 위해 임의의 노드 주소 저장
	Node* p = head; // 먼저, p <- 원본 연결리스트 저장
	Node* q = NULL; // 나중에 역 연결리스트 출력을 담당하는 공간
	Node* r; // 쌓기 전 임의의 공간
	while (p != NULL)
	{
		r = q; // 이전 받아와 쌓아놓은 노드들 임의로 저장하는 공간
		q = p; // 방금 가져온 연결리스트 젤 앞 노드를 q에 저장
		p = p->link; // 젤 앞 노드 업데이트
		q->link = r; // q에 있는 방금 가져온 노드 뒤에 이전에 있던 노드들 쌓기
	}

	return q; // 역 연결리스트 출력
}


void Print_Linked_List(Node* head) // 연결노드 리스트 출력
{
	Node* iter = head; // 헤드부터 반복될 iter 노드 선언.
	int i = 0; // i=0부터
	while (iter != NULL) // iter 노드가 NULL이 될 때까지
	{
		printf("node[%d]:%d", i, iter->data); // 반복되는 i번째 노드의 i와 data값 출력.
		iter = iter->link; // iter 노드를 다음 노드로 바꿔주기
		if (iter != NULL) printf(" -> ");
		i++;
	}
	printf("\n");
}
