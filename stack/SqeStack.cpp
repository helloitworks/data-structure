#include <iostream.h>
#include <assert.h>

class Stack
{
public:
	Stack(int size);
	void Push(int data);
	void Pop();
	int Top();

	bool IsEmpty();
	bool IsFull();
	void MakeEmpty();
	void Print();
	~Stack();
private:
	int *stack;
	int top;    
	int maxSize;
	
};

Stack::Stack(int size)
{
	maxSize = size;
	stack = new int[size];
	top = -1;
}

void Stack::Push(int data)
{
	assert(top != maxSize -1);
	stack[++top] = data;
}

void Stack::Pop()
{
	assert(top != -1);
	top--;
}

int Stack::Top()
{
	assert(top != -1);
	return stack[top];
}


bool Stack::IsEmpty()
{
	return top == -1;
}

bool Stack::IsFull()
{
	return top == maxSize - 1;
}

void Stack::MakeEmpty()
{
	top = -1;
}

void Stack::Print()
{
	for (int i=0; i<=top; i++)
	{
		cout<<stack[i]<<ends;
	}
	cout<<endl;
}

Stack::~Stack()
{
	delete []stack;
}

void main()
{
	int size = 10;
	Stack stack(size);
	
	for (int i = 0; i <= size - 1; i++)
	{
		stack.Push(i);
		
	}
	stack.Print();

	int top = stack.Top();
	cout<<"top:"<<top<<endl;

	for ( i=0; i<=3; i++)
	{
		stack.Pop();
	}
	stack.Print();



}
