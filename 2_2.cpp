// 문제
//희소행렬 A의 전치행렬 B를 구하는 3번째 알고리즘을 구현하여라.

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
//실습 과제 1에서 작성한 코드에 아래의 함수를 추가 구현
//Element* Transpose_Triple2(Element S_a[]) 함수 구현

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

// 아래 함수 외엔 P2_1 과제와 똑같은 코드이므로 아래 함수에만 주석을 달았습니다.
// 희소행렬 S_a를 입력 받아 전치행렬 S_b를 출력하는 함수
// 2_1의 함수는 current가 계속 열을 돌면서 0부터 같은 값을 찾아 차례로 저장하였는데
// 2_2의 아래 함수는 전치행렬 S_b에 들어갈 행의 위치 정보를 미리 계산해서 저장하는 방식이다.
Element* Transpose_Triple2(Element S_a[]) { // 입력: S_a
   int no = S_a[0].value; // S_a의 첫 행의 value 값인 0이 아닌 값의 개수
   Element* S_b = new Element[MAX_ELEMENTS]; // 전치행렬 S_b
   S_b[0].row = S_a[0].col; // S_b의 row 개수 = S_a의 col 개수
   S_b[0].col = S_a[0].row; // S_b의 col 개수 = S_a의 row 개수
   S_b[0].value = no; // S_b의 값 개수 = S_a의 값 개수

   if (no > 0) { // 값이 있을 때 실행
      int* row = new int[S_a[0].col]; // S_b의 row의 빈도수를 저장하는 배열
      int* pos = new int[S_a[0].col]; // 위치 정보를 저장하는 배열

      for (int i = 0; i < S_a[0].col; i++) { // row  배열 초기화
         row[i] = 0;
      }
      for (int i = 1; i <= no; i++) { // S_a의 col의 빈도수(=S_b의 row)를 측정해서 row 배열에 저장
         row[S_a[i].col]++;
      }
      pos[0] = 1; // pos[0]이 1인 이유는 희소행렬의 첫 행을 제외해야 하기 때문
      for (int i = 1; i < S_a[0].col; i++) {
         pos[i] = pos[i - 1] + row[i - 1]; // 그 다음 pos 위치는 이전 pos 숫자 + 이전 row 개수
      }
      for (int i = 1; i <= no; i++) { // pos 위치 기준으로 전치행렬 S_b 생성
         int abs_pos = pos[S_a[i].col]; // abs_pos는 pos에 저장된 인덱스값.
         pos[S_a[i].col]++; // 다음 값을 저장하려면 pos에 저장된 인덱스값들에 +1씩 해줘야 함.
         S_b[abs_pos].row = S_a[i].col; // 전치행렬 S_b row에 S_a col 저장
         S_b[abs_pos].col = S_a[i].row; // 전치행렬 S_b col에 S_a row 저장
         S_b[abs_pos].value = S_a[i].value; // 전치행렬 S_b value에 S_a value 저장
      }
      delete[] row; // row 동적 메모리 할당 해제
      delete[] pos; // pos 동적 메모리 할당 해제
   }

   return S_b; // 전치행렬 S_b 출력
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

// 과제에 대한 고찰
// 중첩 반복문을 없애 시간 복잡도를 줄이는 방법을 배웠다.
// 앞서 배운 2_1의 0이 많은 행렬의 공간 복잡도까지 고려하므로
// 시간 복잡도, 공간 복잡도 모두 줄일 수 있는 방법을 배웠다.