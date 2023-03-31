// 문제
 //희소행렬 A의 전치행렬 B를 구하는 2번째 알고리즘을 구현하여라.

// 입력: 희소행렬 Sparse_A
 //Element Sparse_A[MAX_ELEMENTS] = { {6,6,7},
   /*   {0, 2, 6},
      { 1,0,5 },
      { 1,4,7 },
      { 2,3,3 },
      { 4,0,8 },
      { 4,1,9 },
      { 5,3,2 } };*/


// 출력
//입력으로 주어진 희소행렬 Sparse_A를 이용해 전치행렬 S_b를 계산하여
//S_b에 저장한 정보를 0을 포함한 전치행렬 전체 항을 화면에 출력

// 조건
//Element* Transpose_Triple1(Element S_a[]) 함수 구현
//void Print_Sparse_Mat(Element arr[]) 함수 구현

#include <iostream>

// 희소행렬의 행 크기 8 지정.(7개의 값 + 1개의 원소 개수 행)
#define MAX_ELEMENTS 8

using namespace std;

// Element 구조체 지정(row num, col num, value)
typedef struct Element {
    int row; //몇 번째의 row에 있는지 (1행은 row 개수)
    int col; //몇 번째의 col에 있는지 (1행은 col 개수)
    int value; // [row,col]의 value가 얼마인지 (1행은 0이 아닌 값의 개수)
}Element;

// 희소행렬 S_a를 입력 받아 전치행렬 S_b를 출력하는 함수
// current를 사용하여 S_a의 열을 계속 돌면서 S_b의 행을 0부터 차례로 추가하는 함수
Element* Transpose_Triple1(Element S_a[]) { // 입력: S_a
    int no = S_a[0].value; // S_a의 첫 행의 value 값인 0이 아닌 값의 개수
    int current;
    Element* S_b = new Element[MAX_ELEMENTS]; // 전치행렬 S_b
    S_b[0].row = S_a[0].col; // S_b의 row 개수 = S_a의 col 개수
    S_b[0].col = S_a[0].row; // S_b의 col 개수 = S_a의 row 개수
    S_b[0].value = no; // S_b의 값 개수 = S_a의 값 개수

    if (no > 0) { // 값이 있을 때 실행
        current = 1; // S_b에 채울 현재 행 = 1 (0인 행은 원소 개수 행이기 때문)
        for (int i = 0; i < S_a[0].col; i++) { // S_a의 col 수
            for (int j = 1; j <= no; j++) { // S_a 행렬의 j번째 col. j는 1행부터 value개수 행까지
                if (S_a[j].col == i) { // S_a 행렬의 j번째 col이 i(0,1,2,3,4,5...)일 때 차례로(i 순서대로) 아래와 같이 저장
                    S_b[current].row = S_a[j].col; // 전치행렬 S_b row에 S_a col 저장
                    S_b[current].col = S_a[j].row; // 전치행렬 S_b col에 S_a row 저장
                    S_b[current].value = S_a[j].value; // 전치행렬 S_b value에 S_a value 저장
                    current = current + 1; // current ++
                }
            }
        }
    }

    return S_b; // 전치행렬 S_b 출력
}
// 희소행렬 출력 함수
void Print_Sparse_Mat(Element arr[]) { // 출력할 arr 입력
    int row = arr[0].row; // 희소행렬 첫 행이므로 row의 개수
    int col = arr[0].col; // 희소행렬 첫 행이므로 col의 개수
    int no = arr[0].value; // 희소행렬 첫 행이므로 value의 개수
    int current = 1; // current = 희소행렬의 첫 행 제외하고 출력하기 위함
    for (int i = 0; i < row; i++) { // row 출력 위한 루프
        for (int j = 0; j < col; j++) { // col 출력 위한 루프
            if ((arr[current].row == i) && (arr[current].col == j)) { // [i,j] 위치의
                printf("%d ", arr[current].value); // value 출력
                current++; // current ++
            }
            else {
                printf("%d ", 0); // 값 없으면 0
            }
        }
        printf("\n"); // 한 행 끝나면 줄바꿈
    }
    printf("\n"); // 행렬 끝나면 줄바꿈

}



// main 함수
int main1() {

    Element Sparse_A[MAX_ELEMENTS] = { {6,6,7}, // 입력, 희소행렬 S_a
       {0,2,6},
       {1,0,5},
       {1,4,7},
       {2,3,3},
       {4,0,8},
       {4,1,9},
       {5,3,2} };

    Print_Sparse_Mat(Sparse_A); // 전치행렬 하기 전 희소행렬 S_a 출력(원본과 전치행렬의 비교를 위함)

    Element* S_b = Transpose_Triple1(Sparse_A); // S_a의 전치행렬 S_b
    Print_Sparse_Mat(S_b); // S_b 출력

    delete[] S_b; // S_b 동적 메모리 할당 해제

    return 0;
}

// 과제에 대한 고찰
// 대부분의 원소가 0인 행렬을 효과적으로 처리할 수 있는 방법을 배웠다.
