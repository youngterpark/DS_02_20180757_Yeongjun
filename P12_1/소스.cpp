#include <cstdio>

void swap(int* n1, int* n2)
{
	int tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}

int Partition(int* random_data, int left, int right)
{
	int low = left + 1;
	int high = right;
	int pivot = random_data[left];
	while (low <= high)
	{
		while (random_data[high] > pivot)
		{
			high = high - 1;
		}
		while ((low <= high) && (random_data[low] <= pivot))
		{
			low = low + 1;
		}
		if (low <= high)
		{
			swap(&random_data[low], &random_data[high]);
			low = low + 1;
			high = high - 1;
		}
	}
	swap(&random_data[left], &random_data[high]);
	return high;
}
void Quick_Sort(int* random_data, int left, int right)
{
	if (left < right)
	{
		int q = Partition(random_data, left, right);
		Quick_Sort(random_data, left, q - 1);
		Quick_Sort(random_data, q + 1, right);
	}
}
int Seq_Search(int* random_data, int key, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (key == random_data[i]) return i;
	}
	return -1;
}
int Bin_Search(int* random_data, int key, int n)
{
	int left = 0;
	int right = n - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (key == random_data[mid]) return mid;
		if (key > random_data[mid])
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return -1;
}
int main()
{
	int random_data[] = { 27, 4, 37, 2, 62, 12, 59, 16, 49, 18 };
	int size = sizeof(random_data) / sizeof(int);
	printf("정렬 전 데이터: ");
	for (int i = 0; i < size; i++) { printf("%d ", random_data[i]); }
	int result = Seq_Search(random_data, 49, size);
	printf("\n\n##순차 탐색##\n");
	if (result != -1) printf("값 %d는 %d 번째에 존재합니다.\n\n", random_data[result], result);
	Quick_Sort(random_data, 0, size - 1); //11.2 참고
	printf("정렬 후 데이터: ");
	for (int i = 0; i < size; i++) { printf("%d ", random_data[i]); }
	printf("\n\n##이진 탐색##\n");
	int key = 52;
	result = Bin_Search(random_data, key, size);
	if (result == -1) printf("%d 값은 존재하지 않습니다.\n", key);
	key = 37;
	result = Bin_Search(random_data, key, size);
	if (result != -1) printf("값 %d는 %d 번째에 존재합니다.\n", key, result);
	return 0;
}
