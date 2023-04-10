#ifndef __MY_LINKED_LIST_H__ //if not define
#define __MY_LINKED_LIST_H__

typedef struct Node { //Node 구조체
	int data; //데이터 필드
	struct Node* link;// 다음 노드의 주소를 저장
}Node;
Node* Create_Node(int newData); //노드 생성
void Destroy_Node(Node* node); //노드 소멸
void Append_Node(Node** head, Node* newNode);//노드 추가
void Append_Node_T(Node** tail, Node* newNode); // Tail 기반 노드 추가
void Print_Circular_Linked_List(Node* head); //원형 연결리스트 출력 함수
void Print_Circular_Linked_List_T(Node* tail); // Tail 기반 원형 연결리스트 출력 함수
#endif
