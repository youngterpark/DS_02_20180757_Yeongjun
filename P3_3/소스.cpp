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
	Node* reverse = Reverse_List(head); //역 연결리스트 구성
	Print_Linked_List(reverse); // 역 연결리스트 전체 출력
	printf("\n");
	return 0;
}

// 고찰
// 역 연결리스트 출력은 뭔가 그냥 반대로 하면 되지 않을까 했는데 생각해보니 어려웠고,
// 임의의 공간(p,q,r)을 만들어서 출력할 수 있다는 솔루션을 배워 연결리스트 자료구조 이해에 도움이 되었다.
