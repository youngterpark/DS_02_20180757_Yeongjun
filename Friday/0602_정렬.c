#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

void Display(int arr[])
{
	for (int k = 0; k < MAX; k++)
	{
		printf("%3d", arr[k]);
	}
	printf("\n\n");
}

void Swap(int arr[], int data1, int data2) // data는 위치정보
{
	int temp = arr[data1];
	arr[data1] = arr[data2];
	arr[data2] = temp;
}

int partition(int arr[], int left, int right)
{
	int pivot = arr[left];
	int low = left + 1;
	int high = right;

	while (low <= high)
	{
		while (pivot >= arr[low] && low <= high)
		{
			low++;
		}
		while (pivot <= arr[high] && high >= left + 1)
		{
			high--;
		}
		if (low <= high)
		{
			Swap(arr, low, high);
		}
	}

	Swap(arr, left, high);
	printf("Pivot = %d\n", pivot);
	return high;
}

void quick_sort(int arr[], int left, int right)
{
	if (left < right)
	{
		int temp = partition(arr, left, right);

		Display(arr);
		quick_sort(arr, left, temp - 1); // 피벗 기준 왼쪽
		quick_sort(arr, temp + 1, right);
	}
}

void Bubble(int B[])
{
	for (int k = MAX - 1; k > 0; k--)
	{
		for (int q = 0; q < k; q++)
		{
			if (B[q] > B[q + 1])
			{
				Swap(B, q, q + 1);
			}
		}
		Display(B);
	}
}

void Insert(int N[])
{
	int temp, pre;
	for (int k = 1; k < MAX; k++)
	{
		temp = N[k];
		for (pre = k - 1; pre >= 0 && N[pre] > temp; pre--)
		{
			N[pre + 1] = N[pre];
		}
		N[pre + 1] = temp;
		Display(N);
	}
}

void main()
{
	int B[MAX], N[MAX], Q[MAX];

	srand(time(NULL));

	for (int k = 0; k < MAX; k++)
	{
		B[k] = rand() % 10 + 1;
		N[k] = rand() % 10 + 1;
		Q[k] = rand() % 10 + 1;
		for (int w = 0; w < k; w++)
		{
			if (B[w] == B[k])
			{
				k--;
				break;
			}
		}
	}
	/*printf("퀵 정렬 전: ");
	Display(Q);

	printf("퀵 정렬 후: ");
	quick_sort(Q, 0, MAX - 1);*/

	/*printf("버블 정렬 전: ");
	Display(B);

	printf("버블 정렬 후: ");
	Bubble(B);*/

	printf("삽입 정렬 전: ");
	Display(N);

	printf("삽입 정렬 후: ");
	Insert(N);
}