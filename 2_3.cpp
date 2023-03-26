// 문제
// 임의의 두 다항식이 주어졌을 때, 두 다항식의 합을 구하는 프로그램을 작성하라.
// 입력: A(x) = 3x^5 + 2x^3 + 2, B(x) = 4x^4 + 5x^3 + 2x
// 출력: C(x) = A(x) + B(x) = 3x^5 + 4x^4 + 7x^3 + 2x + 2
// 조건: 계수와 차수만 저장

// 알고리즘 Poly_Add를 구현해보자.
// 입력: 다항식 A와 B가 저장된 구조체 배열 poly, 다항식의 시작과 끝을 가리키는 인덱스 변수(As / Ae, Bs / Be), 빈 공간의 시작위치 avail
// 출력: A와 B를 더한 다항식 C

#include <iostream>
#define NO_OF_TERMS 20 // 배열 Poly의 크기
using namespace std;

typedef struct Term { // 다항식 저장 자료구조 설계 (계수, 차수)
	int coef; // 계수
	int expon; // 차수
}Term;

int Cs; // 다항식 C의 시작 인덱스를 저장하는 변수
int Ce; // 다항식 C의 종료 인덱스를 저장하는 변수

void insert(Term poly[], int avail, int coef, int expon) { // 다항식 C의 항을 저장하기 위해 avail 위치에 삽입하는 insert 함수
	poly[avail].coef = coef; // 현재 칸에 계수 저장
	poly[avail].expon = expon; // 현재 칸에 차수 저장
}

// As: A 다항식의 시작 인덱스를 저장하는 변수
// Ae: A 다항식의 종료 인덱스를 저장하는 변수
// Bs: B 다항식의 시작 인덱스를 저장하는 변수
// Be: B 다항식의 종료 인덱스를 저장하는 변수
// avail: 빈 공간의 시작 인덱스를 저장하는 변수
void Poly_Add(Term poly[], int As, int Ae, int Bs, int Be, int* avail) { // 배열 poly에 저장된 A 다항식과 B 다항식을 더해서 poly 뒤에 저장하는 함수
	Cs = *avail; // 다항식 C의 시작 인덱스 = Poly 배열의 빈 공간 중 첫 칸
	while (As <= Ae && Bs <= Be) { // A 혹은 B가 남지 않은 경우 while 문 종료
		if (poly[As].expon > poly[Bs].expon) { // A의 차수가 큰 경우
			insert(poly, (*avail), poly[As].coef, poly[As].expon); // avail 위치에 삽입
			As++;
		}
		else if (poly[As].expon == poly[Bs].expon) { // A와 B의 차수가 같은 경우
			int sumCoef = poly[As].coef + poly[Bs].coef; // sumCoef: A와 B의 계수를 더해서 저장하는 변수
			if (sumCoef) { // sumCoef가 0이 아니라면
				insert(poly, (*avail), sumCoef, poly[As].expon); // avail 위치에 삽입
			}
			else { // 0이라면
				(*avail) = (*avail) - 1; // 뒤에 (*avail)++ 가 있으므로 -1 해줘야함
			}
			As++;
			Bs++;

		}
		else if (poly[Bs].expon > poly[As].expon) { // B의 차수가 큰 경우
			insert(poly, (*avail), poly[Bs].coef, poly[Bs].expon); // avail 위치에 삽입
			Bs++;
		}
		(*avail)++;
	}
	for (int i = As; i <= Ae; i++) { // A 잔여항 복사
		insert(poly, (*avail), poly[i].coef, poly[i].expon); // avail 위치에 삽입
		(*avail)++;
	}
	for (int i = Bs; i <= Be; i++) { // B 잔여항 복사
		insert(poly, (*avail), poly[i].coef, poly[i].expon); // avail 위치에 삽입
		(*avail)++;
	}
	Ce = (*avail) - 1; // C 다항식의 종료 인덱스 변수에 지금까지 저장한 위치(avail 위치 한 칸 앞) 저장
}

void Print_Poly(Term poly[], int As, int Ae, int Bs, int Be, int avail) { // 배열 Poly 출력 함수
	for (int i = 0; i < avail; i++) { // 배열 Poly 처음부터 저장된 위치(avail 위치 한 칸 앞)까지 출력
		if (i == As)		printf("Polynominal A:  "); // A 다항식 출력 시작
		else if (i == Bs)	printf("Polynominal B:  "); // B 다항식 출력 시작
		else if (i == Cs)	printf("Polynominal C:  "); // C 다항식 출력 시작

		printf("%d*x^%d", poly[i].coef, poly[i].expon); // 계수*x^차수 출력
		if (i == Ae || i == Be || i == Ce) printf("\n\n"); // 다항식 끝나면 줄바꿈 두 번 출력
		else printf(" + "); // 끝이 아니라면 " + " 출력
	}
}

int main(void) { // main 함수
	Term poly[NO_OF_TERMS] = { {3,5},{2,3},{2,0},{4,4},{5,3},{2,1} }; // A 다항식과 B 다항식 입력
	int As = 0; // As: A 다항식의 시작 인덱스를 저장하는 변수
	int Ae = 2; // Ae: A 다항식의 종료 인덱스를 저장하는 변수
	int Bs = 3; // Bs: B 다항식의 시작 인덱스를 저장하는 변수
	int Be = 5; // Be: B 다항식의 종료 인덱스를 저장하는 변수
	int avail = 6; // avail: 빈 공간의 시작 인덱스를 저장하는 변수
	Poly_Add(poly, As, Ae, Bs, Be, &avail); // 배열 poly에 저장된 A 다항식과 B 다항식을 더해서 poly 뒤에 저장하는 함수
	Print_Poly(poly, As, Ae, Bs, Be, avail); // 배열 poly 출력하는 함수
	return 0;
}

// 과제에 대한 고찰
// 1. 구조체형 배열을 사용하여 {계수, 차수} 형태로 다항식의 자료구조를 설계하는 점을 배웠다.
// 2. {계수, 차수} 형태의 배열로 구성된 자료구조의 단점으로 차수가 100 혹은 그 이상으로 높은 경우 연결리스트로 자료구조를 설계하여야 한다는 점을 배웠다.