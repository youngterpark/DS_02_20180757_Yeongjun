// ����
 //������ A�� ��ġ��� B�� ���ϴ� 2��° �˰����� �����Ͽ���.

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
       //Element* Transpose_Triple1(Element S_a[]) �Լ� ����
       //void Print_Sparse_Mat(Element arr[]) �Լ� ����

#include <iostream>

// �������� �� ũ�� 8 ����.(7���� �� + 1���� ���� ���� ��)
#define MAX_ELEMENTS 8

using namespace std;

// Element ����ü ����(row num, col num, value)
typedef struct Element {
    int row; //�� ��°�� row�� �ִ��� (1���� row ����)
    int col; //�� ��°�� col�� �ִ��� (1���� col ����)
    int value; // [row,col]�� value�� ������ (1���� 0�� �ƴ� ���� ����)
}Element;

// ������ S_a�� �Է� �޾� ��ġ��� S_b�� ����ϴ� �Լ�
// current�� ����Ͽ� S_a�� ���� ��� ���鼭 S_b�� ���� 0���� ���ʷ� �߰��ϴ� �Լ�
Element* Transpose_Triple1(Element S_a[]) { // �Է�: S_a
    int no = S_a[0].value; // S_a�� ù ���� value ���� 0�� �ƴ� ���� ����
    int current;
    Element* S_b = new Element[MAX_ELEMENTS]; // ��ġ��� S_b
    S_b[0].row = S_a[0].col; // S_b�� row ���� = S_a�� col ����
    S_b[0].col = S_a[0].row; // S_b�� col ���� = S_a�� row ����
    S_b[0].value = no; // S_b�� �� ���� = S_a�� �� ����

    if (no > 0) { // ���� ���� �� ����
        current = 1; // S_b�� ä�� ���� �� = 1 (0�� ���� ���� ���� ���̱� ����)
        for (int i = 0; i < S_a[0].col; i++) { // S_a�� col ��
            for (int j = 1; j <= no; j++) { // S_a ����� j��° col. j�� 1����� value���� �����
                if (S_a[j].col == i) { // S_a ����� j��° col�� i(0,1,2,3,4,5...)�� �� ���ʷ�(i �������) �Ʒ��� ���� ����
                    S_b[current].row = S_a[j].col; // ��ġ��� S_b row�� S_a col ����
                    S_b[current].col = S_a[j].row; // ��ġ��� S_b col�� S_a row ����
                    S_b[current].value = S_a[j].value; // ��ġ��� S_b value�� S_a value ����
                    current = current + 1; // current ++
                }
            }
        }
    }

    return S_b; // ��ġ��� S_b ���
}
// ������ ��� �Լ�
void Print_Sparse_Mat(Element arr[]) { // ����� arr �Է�
    int row = arr[0].row; // ������ ù ���̹Ƿ� row�� ����
    int col = arr[0].col; // ������ ù ���̹Ƿ� col�� ����
    int no = arr[0].value; // ������ ù ���̹Ƿ� value�� ����
    int current = 1; // current = �������� ù �� �����ϰ� ����ϱ� ����
    for (int i = 0; i < row; i++) { // row ��� ���� ����
        for (int j = 0; j < col; j++) { // col ��� ���� ����
            if ((arr[current].row == i) && (arr[current].col == j)) { // [i,j] ��ġ��
                printf("%d ", arr[current].value); // value ���
                current++; // current ++
            }
            else {
                printf("%d ", 0); // �� ������ 0
            }
        }
        printf("\n"); // �� �� ������ �ٹٲ�
    }
    printf("\n"); // ��� ������ �ٹٲ�

}



// main �Լ�
int main() {

    Element Sparse_A[MAX_ELEMENTS] = { {6,6,7}, // �Է�, ������ S_a
       {0,2,6},
       {1,0,5},
       {1,4,7},
       {2,3,3},
       {4,0,8},
       {4,1,9},
       {5,3,2} };

    Print_Sparse_Mat(Sparse_A); // ��ġ��� �ϱ� �� ������ S_a ���(������ ��ġ����� �񱳸� ����)

    Element* S_b = Transpose_Triple1(Sparse_A); // S_a�� ��ġ��� S_b
    Print_Sparse_Mat(S_b); // S_b ���

    delete[] S_b; // S_b ���� �޸� �Ҵ� ����

    return 0;
}

// ������ ���� ����
// �ð� ���⵵�� ����ϴ� ����� ��ø ������ ����, �������� �ȴٴ� ���� �н��� �� ��ø ������ �� ��� �ڴٰ� �����Ծ��µ�
// ��ø ������ ����ϴ� ��� ��� �迭���� �� �˰���� ���� �������� ����Ͽ� �ð� ���⵵�� ���� �� �ִٴ� ���� �����.
// ���� ��κ��� ���Ұ� 0�� ����� ȿ�������� ó���� �� �ִ� ����� �����.