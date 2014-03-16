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
	void Display();
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
	Node *newNode = new Node(data,temp->next);
	temp->next = newNode;
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

	Node *pre = head->next;
	Node *cur = pre->next;
	Node *next = NULL;

	while (cur != NULL)
	{
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}

	head->next ->next= NULL;//将原来的第一个节点的指针域赋为空，作为尾节点
    head->next = pre; //将原来的尾节点变成新链表的第一个节点（头结点所指向的节点）
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
	cout<<"Reverse:";
	list.Reverse();
	list.Display();
	
}