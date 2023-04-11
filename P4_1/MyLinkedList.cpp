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
	Node* tail; //헤드에서 타고 들어갈 tail노드, tail노드 link에 newNode 추가해야 함
	if ((*head) == NULL) // 현재 헤드가 비어있으면, 새로운 노드를 헤드로 설정
	{
		*head = newNode; // 헤드노드 = newNode
		newNode->link = newNode; // 원형 연결리스트이기 때문, link=자기자신
	}
	else
	{
		tail = *head; // 일반적인 경우, tail=헤드노드 초기화 한 후,
		do
		{
			tail = tail->link; // link따라 타고 들어감
		} while (tail->link != *head); // tail의 link가 head노드를 가리키면 tail이 마지막 노드임
		tail->link = newNode; // tail의 link에 newNode 추가
		newNode->link = *head; // 원형 연결리스트, newNode link가 head노드 가리키도록
	}
}

void Append_Node_T(Node** tail, Node* newNode) { //Tail 기반 노드 추가
	if ((*tail) == NULL) // Null일 경우
	{
		*tail = newNode; // tail = newNode
		newNode->link = newNode; // 원형 연결리스트, link = 자기 자신
	}
	else
	{
		newNode->link = (*tail)->link; // 일반적으로 newNode의 link <- 원래 tail의 link
		(*tail)->link = newNode; // tail의 link <- newNode
		*tail = newNode; // tail을 newNode로 업데이트
	}
}

void Print_Circular_Linked_List(Node* head) { // 원형 연결리스트 출력
	if (head == NULL) return; //헤드가 비어있으면, 함수 종료
	Node* iter = head; // iter = head부터 시작
	int i = 0;
	do
	{
		printf("node[%d]:%d", i, iter->data); // i = 0 부터 iter, iter.data 출력
		iter = iter->link; // iter을 iter의 link 노드로 업데이트
		if (iter != NULL) printf(" -> ");
		i++;
	} while (iter != head); //헤드로 돌아올 때까지 반복
	printf("head:%d", iter->data); //마지막 노드가 헤드로 연결되었는지 확인
	printf("\n");
}
void Print_Circular_Linked_List_T(Node* tail) { // Tail 기반 원형 연결리스트 출력 함수
	Node* head = tail->link; // 'tail의 link가 head'라는 정보로 탐색
	if (head == NULL) return; //헤드가 비어있으면, 함수 종료
	Node* iter = head; // iter = head
	int i = 0;
	do
	{
		printf("node[%d]:%d", i, iter->data); // i = 0 부터 iter, iter.data 출력
		iter = iter->link; // iter을 iter의 link 노드로 업데이트
		if (iter != NULL) printf(" -> ");
		i++;
	} while (iter != head); //헤드로 돌아올 때까지 반복
	printf("head:%d", iter->data); //마지막 노드가 헤드로 연결되었는지 확인
	printf("\n");
}
