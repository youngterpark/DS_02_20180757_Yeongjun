#include <iostream>
#include "MyDoublyLinkedList.h"
using namespace std;

// remove 0이랑 2도 테스트 해보기
int main(void) {
	Node* head = NULL;
	DLL_Append_Node(&head, DLL_Create_Node(15)); // 헤드노드 15노드 생성
	DLL_Append_Node(&head, DLL_Create_Node(31)); // 31 노드 생성
	DLL_Print_Linked_List(head); // 노드 출력 (15, 31)
	//DLL_Get_Node() 함수 기능 테스트
	Node* temp = DLL_Get_Node(head, 0); // 15노드 get test
	printf("Get_Node() test: %d\n", temp->data); // 확인 출력
	//Insert_Node_After() 함수 기능 테스트
	DLL_Insert_Node_After(DLL_Get_Node(head, 0), DLL_Create_Node(25)); // get한 15노드 뒤에 25 노드 생성
	DLL_Print_Linked_List(head); // 노드 출력 (15, 25, 31)
	//Remove_Node() 함수 기능 테스트
	DLL_Remove_Node(&head, DLL_Get_Node(head, 0)); // 15 노드 삭제
	DLL_Append_Node(&head, DLL_Create_Node(41)); // 41 노드 생성
	DLL_Print_Linked_List(head); // 노드 출력 (25, 31, 41)
	DLL_Print_Linked_List_Reverse(DLL_Get_Node(head, 2)); // 노드 뒤집기 출력 (41, 31, 25)

	printf("\n");
	return 0;
}

// 4.3 고찰
