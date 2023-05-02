#ifndef __MY__CIRCULAR_QUEUE_HPP__
#define __MY__CIRCULAR_QUEUE_HPP__
#define QUEUE_SIZE 100
template <typename T>
class CircularQueue {
private:
	int front;
	int rear;
	T* arr;
	int qSize;
public:
	CircularQueue() {
		front = -1;
		rear = -1;
		arr = new T[QUEUE_SIZE];
		qSize = QUEUE_SIZE;
	}
	CircularQueue(int size) {
		front = -1;
		rear = -1;
		arr = new T[size];
		qSize = size;
	}
	bool IsEmpty(){
		return (front == rear);
	}
	bool IsFull() {
		return (front == (rear + 1) % QUEUE_SIZE);
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
