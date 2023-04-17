// 실습과제 4.2
// 두 개의 연결리스트를 하나의 연결리스트로 합병하는 함수를 구현해보자.
// Node* Merge_List(Node* head_a, Node* head_b)
//Input: 오름차순으로 정렬된 두 개의 연결리스트 헤드 포인터 (head_a, head_b)
//Output: 두 연결리스트를 합병한 연결리스트의 헤드 포인터

#include <iostream>
#include "MyLinkedList.h"
using namespace std;

int main(void) {
	Node* head_a = NULL; // head_a
	Node* head_b = NULL; // head_b
	Node* head_c = NULL; // head_c

	//a 연결리스트 구성
	Append_Node(&head_a, Create_Node(10)); // 1o 노드 추가
	Append_Node(&head_a, Create_Node(20)); // 2o 노드 추가
	Append_Node(&head_a, Create_Node(30)); // 30 노드 추가
	//b 연결리스트 구성
	Append_Node(&head_b, Create_Node(15)); // 15 노드 추가
	Append_Node(&head_b, Create_Node(25)); // 25 노드 추가
	Append_Node(&head_b, Create_Node(27)); // 27 노드 추가
	Append_Node(&head_b, Create_Node(28)); // 28 노드 추가
	//a,b 연결리스트 출력
	Print_Linked_List(head_a); //a출력
	Print_Linked_List(head_b); //b출력
	//연결리스트 합병 함수 호출
	head_c = Merge_List(head_a, head_b); //a랑 b를 합병
	//합병된 연결리스트 출력
	Print_Linked_List(head_c);
	return 0;
}
