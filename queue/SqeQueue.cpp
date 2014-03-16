#include <iostream.h>
#include <assert.h>

struct Node
{
	int data;
	Node *next;
};

class Queue
{
public:
	Queue(int n);
	void EnQueue(int data);
	void DeQueue();
	int Front();
	bool IsEmpty();
	bool IsFull();
	int Size();
private:
	int *queue;
	int front;
	int rear;
	int size;
	int maxSize;

};

Queue::Queue(int maxSize)
{
	this->maxSize = maxSize;
	//Ҫ������һ���ڴ棬Ԥ��һ���յ�λ�ø�rear, ����rear��front��ȵ�ʱ���޷������ǿջ�����
	queue = new int[maxSize + 1];
	front = rear = 0;
	size = 0;
}

void Queue::EnQueue(int data)
{
	assert(!IsFull());
	size++;
	queue[rear] = data;
	rear = (rear + 1) % (maxSize + 1);
}

void Queue::DeQueue()
{
	assert(!IsEmpty());
	size--;
	front = (front + 1) % (maxSize + 1);
}

int Queue::Front()
{
	assert(!IsEmpty());
	return queue[front];
}

bool Queue::IsEmpty()
{
	return size == 0;
}

bool Queue::IsFull()
{
	return size == maxSize;
}

int Queue::Size()
{
	return size;
}

void main()
{
	int n = 10;
	Queue queue(n);
	for (int i = 0; i < n; i++)
	{
		queue.EnQueue(i);
	}
	queue.DeQueue();
	cout<<"Size:"<<queue.Size()<<endl;
	cout<<"front:"<<queue.Front()<<endl;

}