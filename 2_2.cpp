// ����
//������ A�� ��ġ��� B�� ���ϴ� 3��° �˰����� �����Ͽ���.

// �Է�: ������ Sparse_A
 //Element Sparse_A[MAX_ELEMENTS] = { {6,6,7},
   /*   {0, 2, 6},
      { 1,0,5 },
      { 1,4,7 },
      { 2,3,3 },
      { 4,0,8 },
      { 4,1,9 },
      { 5,3,2 } };*/

// ���
//�Է����� �־��� ������ Sparse_A�� �̿��� ��ġ��� S_b�� ����Ͽ�
//S_b�� ������ ������ 0�� ������ ��ġ��� ��ü ���� ȭ�鿡 ���

// ����
//�ǽ� ���� 1���� �ۼ��� �ڵ忡 �Ʒ��� �Լ��� �߰� ����
//Element* Transpose_Triple2(Element S_a[]) �Լ� ����

#include <iostream>
#define MAX_ELEMENTS 8

using namespace std;

typedef struct Element {
   int row;
   int col;
   int value;
}Element;

Element* Transpose_Triple1(Element S_a[]) {
   int no = S_a[0].value;
   int current;
   Element* S_b = new Element[MAX_ELEMENTS];
   S_b[0].row = S_a[0].col;
   S_b[0].col = S_a[0].row;
   S_b[0].value = no;

   if (no > 0) {
      current = 1;
      for (int i = 0; i < S_a[0].col; i++) {
         for (int j = 0; j <= no; j++) {
            if (S_a[j].col == i) {
               S_b[current].row = S_a[j].col;
               S_b[current].col = S_a[j].row;
               S_b[current].value = S_a[j].value;
               current = current + 1;
            }
         }
      }
   }

   return S_b;
}

// �Ʒ� �Լ� �ܿ� P2_1 ������ �Ȱ��� �ڵ��̹Ƿ� �Ʒ� �Լ����� �ּ��� �޾ҽ��ϴ�.
// ������ S_a�� �Է� �޾� ��ġ��� S_b�� ����ϴ� �Լ�
// 2_1�� �Լ��� current�� ��� ���� ���鼭 0���� ���� ���� ã�� ���ʷ� �����Ͽ��µ�
// 2_2�� �Ʒ� �Լ��� ��ġ��� S_b�� �� ���� ��ġ ������ �̸� ����ؼ� �����ϴ� ����̴�.
Element* Transpose_Triple2(Element S_a[]) { // �Է�: S_a
   int no = S_a[0].value; // S_a�� ù ���� value ���� 0�� �ƴ� ���� ����
   Element* S_b = new Element[MAX_ELEMENTS]; // ��ġ��� S_b
   S_b[0].row = S_a[0].col; // S_b�� row ���� = S_a�� col ����
   S_b[0].col = S_a[0].row; // S_b�� col ���� = S_a�� row ����
   S_b[0].value = no; // S_b�� �� ���� = S_a�� �� ����

   if (no > 0) { // ���� ���� �� ����
      int* row = new int[S_a[0].col]; // S_b�� row�� �󵵼��� �����ϴ� �迭
      int* pos = new int[S_a[0].col]; // ��ġ ������ �����ϴ� �迭

      for (int i = 0; i < S_a[0].col; i++) { // row  �迭 �ʱ�ȭ
         row[i] = 0;
      }
      for (int i = 1; i <= no; i++) { // S_a�� col�� �󵵼�(=S_b�� row)�� �����ؼ� row �迭�� ����
         row[S_a[i].col]++;
      }
      pos[0] = 1; // pos[0]�� 1�� ������ �������� ù ���� �����ؾ� �ϱ� ����
      for (int i = 1; i < S_a[0].col; i++) {
         pos[i] = pos[i - 1] + row[i - 1]; // �� ���� pos ��ġ�� ���� pos ���� + ���� row ����
      }
      for (int i = 1; i <= no; i++) { // pos ��ġ �������� ��ġ��� S_b ����
         int abs_pos = pos[S_a[i].col]; // abs_pos�� pos�� ����� �ε�����.
         pos[S_a[i].col]++; // ���� ���� �����Ϸ��� pos�� ����� �ε������鿡 +1�� ����� ��.
         S_b[abs_pos].row = S_a[i].col; // ��ġ��� S_b row�� S_a col ����
         S_b[abs_pos].col = S_a[i].row; // ��ġ��� S_b col�� S_a row ����
         S_b[abs_pos].value = S_a[i].value; // ��ġ��� S_b value�� S_a value ����
      }
      delete[] row; // row ���� �޸� �Ҵ� ����
      delete[] pos; // pos ���� �޸� �Ҵ� ����
   }

   return S_b; // ��ġ��� S_b ���
}

void Print_Sparse_Mat(Element arr[]) {
   int row = arr[0].row;
   int col = arr[0].col;
   int no = arr[0].value;
   int current = 1;
   for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
         if ((arr[current].row == i) && (arr[current].col == j)) {
            printf("%d ", arr[current].value);
            current++;
         }
         else {
            printf("%d ", 0);
         }
      }
      printf("\n");
   }
   printf("\n");

}




int main() {

   Element Sparse_A[MAX_ELEMENTS] = { {6,6,7},
      {0,2,6},
      {1,0,5},
      {1,4,7},
      {2,3,3},
      {4,0,8},
      {4,1,9},
      {5,3,2} };

   Print_Sparse_Mat(Sparse_A);
   Element* S_b = Transpose_Triple2(Sparse_A);
   Print_Sparse_Mat(S_b);

   return 0;
}

// ������ ���� ����
// ��ø �ݺ����� ���� �ð� ���⵵�� ���̴� ����� �����.
// �ռ� ��� 2_1�� 0�� ���� ����� ���� ���⵵���� ����ϹǷ�
// �ð� ���⵵, ���� ���⵵ ��� ���� �� �ִ� ����� �����.