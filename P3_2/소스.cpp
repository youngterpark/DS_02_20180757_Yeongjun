//실습과제3.1
// 기본적인 연결리스트를 구현해보자
// 아래 세 함수를 구현
//// Node* Create_Node(int newData);
//// void Destroy_Node(Node* node);
//// void Append_Node(Node** head, Node* newNode);


//실습과제3.2
// 3.1에서 구현한 연결리스트에 기능을 추가해보자
//// 노드 탐색
//// 특정 위치의 노드를 찾는 기능
//// 해당 위치의 노드의 주소를 반환
//// Node* Get_Node(Node* head, int pos);
//// 노드 삭제
//// 임의의 위치에 있는 노드를 삭제하는 기능
//// void Remove_Node(Node** head, Node* targetNode)
//// 노드 삽입
//// 임의의 위치에 새로운 노드를 삽입하는 기능
//// void Insert_Node_After(Node* currentNode, Node* newNode)

#include <iostream>
#include "MyLinkedList.h"
using namespace std;

int main(void) {
	Node* head = NULL; //head노드 NULL
	// 기본 노드 생성
	Append_Node(&head, Create_Node(15)); //15노드 생성 및 추가
	Append_Node(&head, Create_Node(31)); //31노드 생성 및 추가
	Append_Node(&head, Create_Node(3)); //3노드 생성 및 추가
	Print_Linked_List(head); // 연결리스트 전체 출력

	//Get_Node()함수 기능 테스트
	Node* temp = Get_Node(head, 0); //임시노드 = 0번째 노드 Get
	printf("Get_Node() test: %d\n", temp->data); //Get_Node()함수 기능 테스트 출력

	//Insert_Node_After() 함수 기능 테스트
	Insert_Node_After(Get_Node(head, 0), Create_Node(25)); //25 노드 생성해서 0번째 노드 뒤에 삽입
	Print_Linked_List(head); // 연결리스트 전체 출력

	//Remove_Node() 함수 기능 테스트
	Remove_Node(&head, Get_Node(head, 0)); //0번째 노드 제거
	Print_Linked_List(head); //연결리스트 전체 출력
	return 0;
}

// 고찰
// Append_Node에 들어가는 head의 더블포인터를 이해하는데 시간이 걸렸습니다.
// Node** head가 head node의 주소이기 때문에 더블포인터를 사용한다는 걸 이해하며 포인터 개념을 확실히 잡을 수 있게 되었습니다.
// 연결리스트 개념 이해는 금방되었다 생각했는데 직접 구현하며 포인터 개념을 정립하며 다시금 깨닫게 되었습니다.
// 실습과제 3.1과 3.2로 나뉘어 구현하여 이해하기에 조금 더 수월하였던 것 같습니다.
// 자료를 저장하기에 좋은 자료구조인 것 같습니다.
