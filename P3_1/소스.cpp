//실습과제3.1
// 기본적인 연결리스트를 구현해보자
// 아래 세 함수를 구현
//// Node* Create_Node(int newData);
//// void Destroy_Node(Node* node);
//// void Append_Node(Node** head, Node* newNode);

#include <iostream>
#include "MyLinkedList.h"
using namespace std;

int main(void) {
	Node* head = NULL; //head노드 NULL
	// 기본 노드 생성
	Append_Node(&head, Create_Node(15)); //15노드 생성 및 추가
	Append_Node(&head, Create_Node(31)); //31노드 생성 및 추가
	Print_Linked_List(head); // 연결리스트 전체 출력
  
	return 0;
}
// 고찰은 실습 3.2에 담았습니다.
