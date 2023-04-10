#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node
{
	int data;
	struct node* link;
}Node;

void Print_Linked_List(Node* top)
{
	Node* iter = top;
	int i = 0;
	while (iter != NULL)
	{
		printf("node[%d]:%d", i, iter->data);
		iter = iter->link;
		if (iter != NULL) printf(" -> ");
		i++;
	}
	printf("\n");
}

void PUSH(Node** top, int value)
{
	Node* newnode = malloc(sizeof(Node));
	newnode->data = value;
	newnode->link = NULL;
	if (*top == NULL)
	{
		*top = newnode;
	}
	else
	{
		newnode->link = *top;
		*top = newnode;
	}

}

int isEmpty(Node* top)
{
	return top==NULL;
}

void POP(Node** top)
{
	if (isEmpty(*top))
	{
		printf("연결리스트가 비어있습니다.");
		return;
	}
	Node* temp = *top;
	*top = (*top)->link;
	free(temp);
}

void main()
{
	int value;
	Node* top = NULL; //top노드 NULL
	PUSH(&top, 15);
	PUSH(&top, 30);
	PUSH(&top, 24);
	PUSH(&top, 3);
	Print_Linked_List(top);

	POP(&top);
	Print_Linked_List(top);

}
