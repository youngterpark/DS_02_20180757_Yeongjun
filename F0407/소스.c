//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//#define S_SIZE 5
//
//typedef int element;
//void Display(element* stack, int* top)
//{
//	int temp = *top;
//	for (int k = S_SIZE - 1; k > 0; k--)
//	{
//		printf("[ %2d ]", k);
//
//		if (k <= temp)
//		{
//			if (k == temp)
//			{
//				printf("|  %2d   | <-- top \n", stack[k]);
//			}
//			else
//			{
//				printf("|  %2d   |\n", stack[k]);
//			}
//		}
//		else
//		{
//			printf("|       |\n");
//		}
//	}
//	printf("       -------\n\n");
//}
//int isFull(int* top)
//{
//	return (*top) == (S_SIZE - 1);
//}
//
//void PUSH(element* stack, int* top, int data)
//{
//	if (isFull(top))
//	{
//		printf("스택이 가득!!");
//		return;
//	}
//	//++(*top);
//	//stack[(*top)] = data;
//
//	stack[++(*top)] = data;
//
//	Display(stack, top);
//}
//
//int isEmpty(int top)
//{
//	return top == -1; // True 1 False 0 반환
//}
//
//element POP(element* stack, int* top)
//{
//	if (isEmpty(*top))
//	{
//		printf("스택이 비어있습니다.");
//		return;
//	}
//	element temp = stack[*top];
//	--(*top);
//	Display(stack,top);
//	return temp;
//}
//
//void main1()
//{
//	srand(time(NULL));
//
//	//자료구조
//	element stack[S_SIZE];
//	int top = -1;
//
//	for (int k = 0; k < 6; k++)
//	{
//		PUSH(stack, &top, rand() % 20 + 1);
//	}
//
//	element temp;
//	for (int k = 0; k < 6; k++)
//	{
//		temp = POP(stack, &top);
//		printf("POP : %d\n", temp);
//	}
//	
//}
