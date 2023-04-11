//실습과제4.1_1 + 4.1_2

#include <iostream>
#include "MyLinkedList.h"
using namespace std;

int main(void) {
	// 하나씩 실행해야 함.
	// 4.1.1
	Node* head = NULL; //head노드 NULL 초기화
	
	// 원형 연결리스트 구성
	Append_Node(&head, Create_Node(15)); // 15노드 추가
	Append_Node(&head, Create_Node(25)); // 25노드 추가
	Append_Node(&head, Create_Node(31)); // 31노드 추가
	Append_Node(&head, Create_Node(24)); // 24노드 추가
	// 원형 연결리스트 출력
	Print_Circular_Linked_List(head);

	// 4.1.2
	Node* tail = NULL; //tail노드 NULL 초기화

	// 원형 연결리스트 구성
	Append_Node_T(&tail, Create_Node(15)); // 15노드 추가
	Append_Node_T(&tail, Create_Node(25)); // 25노드 추가
	Append_Node_T(&tail, Create_Node(31)); // 31노드 추가
	Append_Node_T(&tail, Create_Node(24)); // 24노드 추가
	// 원형 연결리스트 출력
	Print_Circular_Linked_List_T(tail);


	return 0;
}

// 고찰
// 때에 맞는 제일 앞에 노드 삽입, 제일 뒤에 노드 삽입이 한계가 많다고 생각했는데
// 원형 연결리스트가 이 고민을 해결해주는 자료구조인 것 같다.
// 비어있을 때 예외처리만 잘한다면, 쉽게 구현 가능한 것 같다.
// 4.1의 헤드에서 link를 타고타고 들어가서 노드 추가하는 방식보다 4.2에서 tail 사용한 추가 방식이 수행시간을 O(1)로 줄일 수 있다는 것을 배웠다.
