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
	printf("���� �� ������: ");
	for (int i = 0; i < size; i++) { printf("%d ", random_data[i]); }
	int result = Seq_Search(random_data, 49, size);
	printf("\n\n##���� Ž��##\n");
	if (result != -1) printf("�� %d�� %d ��°�� �����մϴ�.\n\n", random_data[result], result);
	Quick_Sort(random_data, 0, size - 1); //11.2 ����
	printf("���� �� ������: ");
	for (int i = 0; i < size; i++) { printf("%d ", random_data[i]); }
	printf("\n\n##���� Ž��##\n");
	int key = 52;
	result = Bin_Search(random_data, key, size);
	if (result == -1) printf("%d ���� �������� �ʽ��ϴ�.\n", key);
	key = 37;
	result = Bin_Search(random_data, key, size);
	if (result != -1) printf("�� %d�� %d ��°�� �����մϴ�.\n", key, result);
	return 0;
}
