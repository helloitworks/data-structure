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
	Queue()
	{
		 Node *temp = new Node;
		 temp ->next = NULL;
		 front = rear = temp;
	}

	void Enter(int data)
	{
		Node *temp = new Node;
		temp->data = data;
		temp->next = NULL;
		rear->next = temp;
		rear = temp;
	}

	void Delete()
	{
		assert(!IsEmpty());
		Node *temp = front->next;
		front->next = temp->next;
		delete temp;
		if (front->next == NULL)
		{
			rear = front;
		}
	}


	int Front()
	{
		assert(rear != front);
		return front->next->data;

	}

	bool IsEmpty()
	{
		return front == rear;
	}

	void Print()
	{
		Node *temp = front->next;
		while (temp != NULL)
		{
			cout<<temp->data<<ends;
			temp = temp->next; // 指针向后移动
		}
		cout<<endl;
	}

private:
	Node *front;
	Node *rear;

};


void main()
{
	Queue queue;
	if (queue.IsEmpty())
	{
		cout<<"IsEmpty"<<endl;
	}
	for (int i=0; i < 10; i++)
	{
		queue.Enter(i);
	}

	queue.Print();
	cout<<"Front: "<<queue.Front()<<endl;
	for (i=0; i < 4; i++)
	{
		queue.Delete();
	}
	queue.Print();
	cout<<"Front: "<<queue.Front()<<endl;

	for (i=0; i < 4; i++)
	{
		queue.Enter(i);
	}
	queue.Print();
	cout<<"Front: "<<queue.Front()<<endl;
}