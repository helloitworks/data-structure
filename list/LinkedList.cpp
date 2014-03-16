#include <iostream.h>
#include <assert.h>

//const int N = 10;

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
	List(){head = new  Node; head->next = NULL;}
	void  Insert(const int &i, const int &data)
	{

		Node *temp = head;
		int index = -1;
		while (temp != NULL)
		{
			if (index == i-1)
			{
				break;
			}
			else
			{
				index ++;
				temp = temp->next;
			}
		}

		assert(temp != NULL);
		Node *p = new Node(data,temp->next);
		temp->next = p;
	}
	void Append(const int &data)
	{
		Node *temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new Node(data,NULL);

	}

	void Reserve()
	{
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
	void Print()
	{
		Node * temp = head->next;
		while (temp != NULL)
		{
			cout<<temp->data<<ends;
			temp = temp->next;
		}
		cout<<endl;
	}
private:
	Node*head;
};

void main()
{
	List list;
	for (int i=0; i<= 1; i++)
	{
		list.Append(i);
	}
	list.Print();

	list.Reserve();
	list.Print();

//	list.Insert(11,22);
	
//	cout<<"Insert(10,22) "<<endl;
//	list.Print();

}