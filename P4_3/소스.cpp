// 실습과제 4.3
// 이중 연결리스트를 구현해보자.
// 아래 함수들을 구현
//Node* DLL_Create_Node(int newData);
//void DLL_Destroy_Node(Node* node);
//void DLL_Append_Node(Node** head, Node* newNode);
//Node* DLL_Get_Node(Node* head, int pos);
//void DLL_Remove_Node(Node** head, Node* targetNode); 
//void DLL_Insert_Node_After(Node* currentNode, Node* newNode);


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
//단일 연결 리스트는 각 노드가 다음 노드를 가리키는 포인터만 가지고 있는 반면, 이중 연결 리스트는 각 노드가 이전 노드와 다음 노드를 가리키는 포인터를 모두 가지고 있다.
//따라서 이중 연결 리스트는 양방향으로 탐색이 가능하며, 노드의 삽입 및 삭제가 단일 연결 리스트보다 더욱 효율적으로 수행된다.
//그리고 역순 출력에 용이하다.
//더블 링크드 리스트 설계 시 삽입/삭제시 이전 노드 정보를 저장하는 prev 변수를 고려해야한다.
