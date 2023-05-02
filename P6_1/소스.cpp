#include <iostream>
#include "MyCircularQueue.hpp"
using namespace std;
int main(void) {
	CircularQueue<int> q;

	// 데이터 삽입
	q.Enqueue(5); q.Enqueue(33); // q에 5, 33, 25, 17 삽입
	q.Enqueue(25); q.Enqueue(17);

	// 전체 데이터 인출
	while (q.IsEmpty() == false) { //q가 비어있지 않다면 -> 반복, 비어있다면 return0;
		printf("%d ", q.Dequeue()); // 비어있지 않을 때 Dequeue로 데이터 인출(앞에서부터, 5 33 25 17)
	}
	return 0;
}
