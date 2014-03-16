#include <iostream.h>
#include <assert.h>

struct Node
{
	Node()
	{
		
	}
	Node(int data,Node *next)
	{
		this->data = data;
		this->next = next;
	}
	int data;
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
	void Reverse();
	void Print();
private:
	Node*head;
};


List::List()
{
	head = new  Node; 
	head->next = NULL;
}

void List::Append(int data)
{
	
	Node *temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new Node(data,NULL);
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
	Node *newNote = new Node(data,temp->next);
	temp->next = newNote;
}

void List::Delete(int index)
{
	Node *temp = FindIndex(index - 1);
	if (temp == NULL)
	{
		return;
	}
	Node * deleteNode = temp->next;
	temp->next = temp->next->next;
	delete deleteNode;
}

void List::Reverse()
{
	/*
	Node *front = NULL;
	Node *p= head->next;
	while(p->next != NULL)
	{
		Node *rear = p->next;
		
		p->next  = front;
		front = p;
		p  = rear;
	}
	p->next = front; // 这一句很重要
	head->next = p;
	*/

	/*
	if (head == NULL)
	return ;
	if (head->next == NULL)
	return ;
	Node* pre = NULL;
	Node* Cur = head;
	Node* Nex = NULL;
	while (Cur!=NULL)
	{
	Nex = Cur->next;
	Cur->next = pre;
	pre = Cur;
	Cur = Nex;
	}
	head  = pre;
	*/
}

void List::Print()
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
	list.Print();
	list.Insert(1,10);
	list.Print();
	list.Delete(1);
	list.Print();
	
}