#include <iostream>
#include "MyLinkedList.h"

Node* Create_Node(int newData) { // 노드 생성 함수
	Node* newnode = new Node; //newnode 할당
	(*newnode).data = newData; //입력받은 data 할당
	(*newnode).link = NULL; //link는 NULL

	return newnode;
}

void Append_Node(Node** head, Node* newNode) { // 제일 끝에 노드 추가하는 함수
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

Node* Merge_List(Node* head_a, Node* head_b) { 노드리스트 두 개 합병
	Node* head_c = NULL; //새로운 노드 만들어서 합병
	while (head_a != NULL && head_b != NULL) //a와 b가 하나라도 비어있지 않을때 비교하며 합병
	{
		if (head_a->data < head_b->data) //b가 더 크면
		{
			Append_Node(&head_c, Create_Node(head_a->data)); // c에 a 노드 젤 앞 노드 추가
			head_a = head_a->link; // a 노드를 링크노드로 업데이트
		}
		else //a가 더 크면
		{
			Append_Node(&head_c, Create_Node(head_b->data)); //c에 b 노드 젤 앞 노드 추가
			head_b = head_b->link; //b 노드를 링크 노드로 업데이트
		}
	}
	while (head_a != NULL) // a가 남았으면 a 남은것들 c에 순서대로 추가
	{
		Append_Node(&head_c, Create_Node(head_a->data)); //c에 a 노드 추가
		head_a = head_a->link; // a 링크노드로 업데이트
	}
	while (head_b != NULL) // b가 남았으면 b 남은것들 c에 순서대로 추가
	{
		Append_Node(&head_c, Create_Node(head_b->data)); //c에 b 노드 추가
		head_b = head_b->link; // b 링크노드로 업데이트
	}
	return head_c;
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
