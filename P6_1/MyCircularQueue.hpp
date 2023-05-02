#ifndef __MY__CIRCULAR_QUEUE_HPP__
#define __MY__CIRCULAR_QUEUE_HPP__
#define QUEUE_SIZE 100
template <typename T>
class CircularQueue {
private:
	int front; // front(인출할 데이터 가리킴)
	int rear; // rear(스택의 top, 인큐를 위함)
	T* arr; // 입력이 다른 자료형들을 데이터로 가지는 array
	int qSize; // qSize = 기본적으론 define한 100, 혹은 입력으로 받은 size
public:
	CircularQueue() {
		front = -1; // front 초기값 -1
		rear = -1; // rear 초기값 -1
		arr = new T[QUEUE_SIZE]; // QUEUE_SIZE 크기의 arr
		qSize = QUEUE_SIZE; // qSize = QUEUE_SIZE
	}
	CircularQueue(int size) {
		front = -1;
		rear = -1;
		arr = new T[size]; // 입력 받은 size 크기의 arr
		qSize = size; // qSize = 입력 받은 size
	}
	bool IsEmpty(){
		return (front == rear); // 비어 있으면 front == rear
	}
	bool IsFull() {
		return (front == (rear + 1) % QUEUE_SIZE); // 가득 차 있으면 front == 
	}
	bool Enqueue(T item) {
		if (IsFull())
		{
			printf("Queue is Full!\n");
			exit(1);
		}
		rear = (rear + 1) % QUEUE_SIZE;
		arr[rear] = item;
	}
	T Dequeue() {
		if (IsEmpty()) {
			printf("Queue is Empty\n");
			exit(1);
		}
		front = (front + 1) % QUEUE_SIZE;
		return arr[front];
	}
	T Peek() {
		return arr[rear];
	}
	~CircularQueue() {
		delete[] arr;
	}
};
#endif // !__MY__CIRCULAR_QUEUE_HPP__
