// 실습과제 3.3
//// 주어진 연결리스트의 역 연결리스트를 구성하는 함수를 구현해보자
#include <iostream>
#include "MyLinkedList.h"
using namespace std;

int main(void) {
	Node* head = NULL; //head노드 NULL

	// 기본 노드 생성
	Append_Node(&head, Create_Node(15)); //15노드 생성 및 추가
	Append_Node(&head, Create_Node(25)); //25노드 생성 및 추가
	Append_Node(&head, Create_Node(31)); //31노드 생성 및 추가
	Append_Node(&head, Create_Node(24)); //24노드 생성 및 추가
	Print_Linked_List(head); // 기본 연결리스트 전체 출력

	// Reverse_List
	Node* reverse = Reverse_List(head);
	Print_Linked_List(reverse); // 역 연결리스트 전체 출력
	printf("\n");
	return 0;
}

// 고찰
