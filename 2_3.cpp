#include <iostream>
#define NO_OF_TERMS 20
using namespace std;

typedef struct Term {
	int coef;
	int expon;
}Term;

int Cs;
int Ce;

void insert(Term poly[], int avail, int coef, int expon) {
	poly[avail].coef = coef;
	poly[avail].expon = expon;
}


void Poly_Add(Term poly[], int As, int Ae, int Bs, int Be, int* avail) {
	// ±¸Çö
	Cs = *avail;
	while (As <= Ae && Bs <= Be) {
		if (poly[As].expon > poly[Bs].expon) {
			insert(poly, (*avail), poly[As].coef, poly[As].expon);
			As++;
		}
		else if (poly[As].expon == poly[Bs].expon) {
			int sumCoef = poly[As].coef + poly[Bs].coef;
			if (sumCoef) {
				insert(poly, (*avail), sumCoef, poly[As].expon);
			}
			else {
				(*avail) = (*avail) - 1;
			}
			As++;
			Bs++;
			
		}
		else if (poly[Bs].expon > poly[As].expon) {
			insert(poly, (*avail), poly[Bs].coef, poly[Bs].expon);
			Bs++;
		}
		(*avail)++;
	}
	for (int i = As; i <= Ae; i++) {
		insert(poly, (*avail), poly[i].coef, poly[i].expon);
		(*avail)++;
	}
	for (int i = Bs; i <= Be; i++) {
		insert(poly, (*avail), poly[i].coef, poly[i].expon);
		(*avail)++;
	}
	Ce = (*avail) - 1;
}

void Print_Poly(Term poly[], int As, int Ae, int Bs, int Be, int avail) {
	for (int i = 0; i < avail; i++) {
		if (i == As)		printf("Polynominal A:  ");
		else if (i == Bs)	printf("Polynominal B:  ");
		else if (i == Cs)	printf("Polynominal C:  ");

		printf("%d*x^%d", poly[i].coef, poly[i].expon);
		if (i == Ae || i == Be || i == Ce) printf("\n\n");
		else printf(" + ");
	}
}

int main(void) {
	Term poly[NO_OF_TERMS] = { {3,5},{2,3},{2,0},{4,4},{5,3},{2,1} };
	int As = 0;
	int Ae = 2;
	int Bs = 3;
	int Be = 5;
	int avail = 6;
	Poly_Add(poly, As, Ae, Bs, Be, &avail);
	printf("%d", Cs);
	Print_Poly(poly, As, Ae, Bs, Be, avail);
	return 0;
}