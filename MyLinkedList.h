#ifndef __MY_LINKED_LIST_H__ //if not define
#define __MY_LINKED_LIST_H__

typedef struct Node { //Node 구조체
	int data; //데이터 필드
	struct Node* link;// 다음 노드의 주소를 저장
}Node;
Node* Create_Node(int newData); //노드 생성 함수
void Append_Node(Node** head, Node* newNode);//노드 추가 함수
Node* Merge_List(Node* head_a, Node* head_b); // 두 연결리스트 합병 함수
void Print_Linked_List(Node* head); //연결리스트 출력 함수
#endif