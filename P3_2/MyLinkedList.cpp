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

Node* Get_Node(Node* head, int pos)//노드 탐색 함수, (head 노드=첫 노드의 주소를 가리킴, 찾고 싶은 노드 위치) pos번째 노드 Get하는 함수
{
	Node* iter = head; // 찾고 싶은 노드가 나올때까지 돌릴 iter 노드에 첫 노드 넣기.
	int i = 0;  // 탐색 한 번당 1씩 커지는 i
	while (pos != i) // i가 찾고싶은 위치 pos랑 같아지면 반복문 종료
	{
		iter = (*iter).link; // iter를 iter의 link 노드로 바꾸면서 다음 노드 탐색
		i++;
	}
	return iter; // 찾고 싶은 위치의 노드 반환
}

void Remove_Node(Node** head, Node* targetNode) //노드 삭제 함수
{
	// 연결을 시켜주고 삭제를 해야 함.
	Node* cur = *head; // 현재 노드 = 헤드 노드
	Node* bef = *head; // 첫 노드를 삭제할 때는 따로 처리함. 두 번째 노드부터 쓰이므로 bef도 헤드 노드로 선언.
	while (cur != NULL) // NULL이 아닐때 반복문(예외 때문)
	{
		if (cur->data == targetNode->data) // 현재 노드 data가 타겟 노드 data와 같다면 삭제 및 이전노드 링크에 다음 노드 주소 넣기.
		{
			if (cur == *head) // 현재노드가 헤드노드라면
			{
				*head = (*head)->link; // 헤드노드를 다음노드로 변경
				Destroy_Node(cur); // 현재노드 소멸
				return;
			}
			else // 현재노드가 헤드노드가 아니라면
			{
				bef->link = cur->link; // 이전노드 링크에 다음노드 주소 저장.
				Destroy_Node(cur); //현재노드 소멸
				return;
			}
		}
		else // 타겟노드가 아니라면, 타겟노드까지 탐색을 진행해야 함.
		{
			bef = cur; // 이전노드는 현재노드로
			cur = cur->link; //현재노드는 다음노드(현재의 링크)로
		}
	}
}

void Insert_Node_After(Node* currentNode, Node* newNode) //현재노드 다음위치에 노드 삽입하는 함수
{
	// <25노드를 15노드 뒤에 삽입>
	if (currentNode->link != NULL) // 현재노드가 마지막이 아니라면
	{
		newNode->link = currentNode->link; // 새로운 노드 링크에 현재노드의 다음노드 입력.
		currentNode->link = newNode; // 현재 노드 링크에 새로운 노드 입력.
	}
	else // 현재노드가 마지막이라면
	{
		currentNode->link = newNode; //현재노드 뒤에 새로운 노드 삽입.
	}
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
