#include <iostream.h>
#include <assert.h>

struct Node
{
	int data;
	Node *next;
};

class Stack
{
public:
	Stack();
	void Push(int data);
	void Pop();
	int Top();
	bool IsEmpty();
	int GetSize();
	void Print();
private:
	Node *top;
	
};

Stack::Stack()
{
	top = NULL;
}

void Stack::Push(int data)
{
	//指针的方向从栈顶向下链接
	Node *temp = new Node;
	temp->data = data;
	temp ->next = top;
	top = temp;
}

void Stack::Pop()
{
	assert(top != NULL);
	Node *temp = top;
	top = top->next;
	delete temp;
}

int Stack::Top()
{
	assert(top != NULL);
	return top->data;
}

bool Stack::IsEmpty()
{
	return top == NULL;
}

int Stack::GetSize()
{
	
	int size = 0;
	Node *temp = top;
	while (temp != NULL)
	{
		size ++;
		temp = temp->next;
	}
	return size;
	
}

void Stack::Print()
{
	Node *temp = top;
	while (temp != NULL)
	{
		cout<<temp->data<<ends;
		temp = temp->next;
	}
	
	cout<<endl;
}

void main()
{
	Stack stack;
	for (int i=0; i<=10-1; i++)
	{
		stack.Push(i);
	}

	stack.Print();
	cout<<"size: "<<stack.GetSize()<<endl;

	cout<<"top: "<<stack.Top()<<endl;

	for ( i=0; i<=4; i++)
	{
		stack.Pop();
	}
	stack.Print();
	cout<<"size: "<<stack.GetSize()<<endl;
	

	
}