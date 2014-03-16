#include <iostream.h>
#include <assert.h>

struct Node
{
	Node(){};
	Node(int data, Node *pre, Node *next)
	{
		this->data = data;
		this->pre = pre;
		this->next = next;
	}
	int data;
	Node *pre;
	Node *next;
};


class List
{
public:
	List();
	void Append(int data);
	Node* FindIndex(int index);
	void Insert(int index, int data);
	void Delete(int index);
	//void Reverse(); todo
	void Display();
private:
	Node*head;
};


List::List()
{
	head = new Node; 
	head->pre = NULL;
	head->next = NULL;
}

void List::Append(int data)
{
	
	Node *temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new Node(data,temp,NULL);
}

Node* List::FindIndex(int index)
{
	Node *temp = head;
	int i = -1;
	while (temp != NULL)
	{
		if (i == index)
		{
			break;
		}
		else
		{
			i ++;
			temp = temp->next;
		}
	}
	return temp;
}

void List::Insert(int index, int data)
{
	Node *temp = FindIndex(index - 1);
	if (temp == NULL)
	{
		return;
	}

	Node *insertNode = new Node(data,temp,temp->next);
	temp->next->pre = insertNode;
	temp->next = insertNode;
}

void List::Delete(int index)
{
	Node *temp = FindIndex(index - 1);
	if (temp == NULL)
	{
		return;
	}
	Node * deleteNode = temp->next;
	deleteNode->next->pre = temp;
	deleteNode->pre->next = deleteNode->next;
	delete deleteNode;
}


void List::Display()
{
	Node * temp = head->next;
	while (temp != NULL)
	{
		cout<<temp->data<<ends;
		temp = temp->next;
	}
	cout<<endl;
}

void main()
{
	List list;
	for (int i=0; i < 10; i++)
	{
		list.Append(i);
	}
	list.Display();
	cout<<"Insert(1,10):";
	list.Insert(1,10);
	list.Display();
	cout<<"Delete(1):";
	list.Delete(1);
	list.Display();

	/*
	cout<<"Reverse:";
	list.Reverse();
	list.Display();
	*/
	
}