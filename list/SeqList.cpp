#include <iostream.h>
#include <assert.h>



class List
{
public:
	List(int maxSize);
	void Append(int data);
	void Insert(int index, int data);
	void Delete(int index);
	bool IsEmpty();
	bool IsFull();
	void Reserve();
	void Print();
private:
	int *list;
	int maxSize;
	int curr;
	int size;
};


List::List(int maxSize)
{
	list = new int[maxSize];
	this->maxSize = maxSize;
	curr = 0;
	size = 0;
}

void List::Append(int data)
{
	assert(!IsFull());
	list[size++] = data;
}

void List::Insert(int index, int data)
{
	assert(!IsFull());
	for (int i = size - 1; i >= index; i-- )
	{
		list[i + 1] = list[i];
	}
	list[index] = data;
	size++;
}

void List::Delete(int index)
{
	assert(!IsEmpty());
	for (int i = index + 1; i < size; i++ )
	{
		list[i - 1] = list[i];
	}
	size--;
}


bool List::IsEmpty()
{
	return size == 0;
}

bool List::IsFull()
{
	return size == maxSize;
}

void List::Print()
{
	for (int i = 0; i < size; i++)
	{
		cout<<list[i]<<" ";
	}
	cout<<endl;
}

void main()
{
	List list(10);
	for (int i=0; i < 9; i++)
	{
		list.Append(i);
	}
	list.Print();
	cout<<"isFull:"<<list.IsFull()<<endl;
	list.Insert(1,10);
	list.Print();
	list.Delete(1);
	list.Print();
	//list.Reserve();
	list.Print();

}