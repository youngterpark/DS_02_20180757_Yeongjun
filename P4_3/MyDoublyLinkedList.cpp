#include <iostream>
#include "MyDoublyLinkedList.h"

Node* DLL_Create_Node(int newData) // 노드 생성
{
	Node* newnode = new Node; //newnode 할당
	newnode->data = newData; //입력받은 data 할당
	newnode->prev = NULL; //prev NULL
	newnode->next = NULL; //next NULL
	return newnode;
}
void DLL_Destroy_Node(Node* node) // 노드 소멸
{
	if (node != NULL) //node가 NULL이 아니면
	{
		delete node; //노드 소멸
	}
}
void DLL_Append_Node(Node** head, Node* newnode) // 노드 추가
{
	if ((*head) == NULL) //현재 헤드가 비어있으면, 새로운 노드를 헤드로 설정
	{
		*head = newnode; //헤드노드 = newNode
	}
	else // 마지막 노드 탐색
	{
		Node* tail = *head; //tail=헤드노드 로 초기화
		while (tail->next != NULL) //tail.next가 NULL이 아니면 반복
		{
			tail = tail->next; //tail의 next로 반복하며 마지막 노드 탐색
		}
		tail->next = newnode; //tail.next가 NULL이면 마지막 노드. next에 newnode 삽입
		newnode->prev = tail; //DLL에 맞게 prev에 기존 tail 연결
	}
}
Node* DLL_Get_Node(Node* head, int pos) // 노드 탐색
{
	Node* iter = head; // 찾고 싶은 노드가 나올때까지 돌릴 iter 노드에 첫 노드 넣기.
	int i = 0; // 탐색 한 번당 1씩 커지는 i
	while (pos != i) // i가 찾고싶은 위치 pos랑 같아지면 반복문 종료
	{
		iter = iter->next; // iter를 iter의 link 노드로 바꾸면서 다음 노드 탐색
		i++;
	}
	return iter; // 찾고 싶은 위치의 노드 반환
}
void DLL_Remove_Node(Node** head, Node* targetNode) // 노드 삭제
{
	if (targetNode->prev == NULL) // 헤드노드 삭제
	{
		*head = (*head)->next; // 헤드노드 바꿔주고
		if (*head != NULL) // 노드가 헤드노드 말고도 더 있는 경우(일반적인 경우)/ 아닐경우 NULL의 prev값은 없으므로 예외처리 해줌.
		{
			(*head)->prev = NULL; // 헤드노드 prev = NULL
		}
		DLL_Destroy_Node(targetNode); // 타겟노드 삭제
		return;
	}
	
	else // 헤드노드 외 노드 삭제
	{
		targetNode->prev->next = targetNode->next; //타겟 전 next와 = 원래 타겟 next 연결
		if (targetNode->next == NULL) // 마지막 노드이면
		{
			DLL_Destroy_Node(targetNode); //그냥 삭제
			return;
		}
		else
		{
			targetNode->next->prev = targetNode->prev; // 타겟 다음의 prev과 원래 타겟 prev 연결
			DLL_Destroy_Node(targetNode); //삭제
			return;
		}
	}
}
void DLL_Insert_Node_After(Node* currentNode, Node* newNode) // 노드 삽입
{
	if (currentNode->next != NULL) // 마지막 노드가 아닐때 삽입
	{
		newNode->next = currentNode->next; // newNode next에 다음 노드 연결
		currentNode->next->prev = newNode; // 다음 노드 prev에 newNode 연결 
		newNode->prev = currentNode; // newNode prev에 cur노드 연결
		currentNode->next = newNode; //cur노드 next에 newNode 연결
	}
	else 
	{
		currentNode->next = newNode; // 마지막 노드면 cur노드 뒤에 newNode 연결
		newNode->prev = currentNode;
	}
}
void DLL_Print_Linked_List(Node* head) // 이중 연결리스트 출력
{
	Node* iter = head; // iter노드 (= head 노드) 생성
	int i = 0; 
	while (iter != NULL) // 마지막노드까지 반복. 마지막 노드 next가 NULL이기 때문.
	{
		printf("N[%d]:%d", i, iter->data); // 출력
		iter = iter->next; // 다음 노드 반복
		if (iter != NULL) printf(" <-> "); // <-> 연결, 마지막 노드 전까지
		i++;
	}
	printf("\n");
}
void DLL_Print_Linked_List_Reverse(Node* tail) // 이중 연결리스트 역순 출력
{
	Node* iter = tail; // iter노드 tail에 생성
	int i = 0;
	while (iter != NULL) // 마지막 노드까지 반복
	{
		printf("N[%d]:%d", i, iter->data); // 출력
		iter = iter->prev; //이전 노드 반복
		if (iter != NULL) printf(" <-> ");
		i++;
	}
	printf("\n");
}
