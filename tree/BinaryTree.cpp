#include <stdio.h>
#include <iostream.h>
#include <stack>
using namespace std;
//例子：
//1 2 3 # # 4 # # 5 6 # # 7 # # 
struct Node
{
	char data;
	Node *lchild, *rchild;
};

class BinaryTree
{
public:
	BinaryTree(Node *&root);
	~BinaryTree();
	void PreOrder(Node *root);
    void PreOrderUsingStack(Node *root);
	void InOrder(Node *root);
	void PostOrder(Node *root);
	void LevelOrder(Node *root);
	int NodeCount(Node *root);
	int BinaryTreeLevel(Node *root);
	
private:
	Node *root;
	void Create(Node *&root);
	void Release(Node *root);
};


BinaryTree::BinaryTree(Node *&root)
{
	this->root = root;
	Create(root);

}
void BinaryTree::Create(Node *&root)
{
	char ch;
    cin>>ch;
	if (ch =='#')
	{
		root = NULL;
	}
	else
	{
		root = new Node;
		root->data = ch;
		Create(root->lchild);
		Create(root->rchild);
	}
}

BinaryTree::~BinaryTree()
{
	Release(root);
}

void BinaryTree::Release(Node *root)
{
	if (root != NULL)
	{
		Release(root->lchild);
		Release(root->rchild);
		delete root;
	}
}

//--前序遍历
void BinaryTree::PreOrder(Node *root)
{
    if (root != NULL)
    {
        printf("%c", root->data);
        PreOrder(root->lchild);
        PreOrder(root->rchild);
    }
}

//--前序非递归遍历
void BinaryTree::PreOrderUsingStack(Node *root)
{

    stack<Node *> stack;
    if (root != NULL)
    {
        printf("%c", root->data);
        stack.push(root);
    }
    while (stack.size() > 1)
    {
        if (root->lchild != NULL)
        {
             printf("%c", root->lchild->data);
             stack.push(root->lchild);
             root = root->lchild;
        }
        else  if (root->rchild != NULL)
        {
            printf("%c", root->rchild->data);
            stack.push(root->rchild);
            root = root->rchild;
        }
        else
        {
            //back
            stack.pop();
            Node *root = stack.top();
            
        }

    }
}


void BinaryTree::InOrder(Node *root)
{
	if (root != NULL)
	{
		InOrder(root->lchild);
		printf("%c", root->data);
		InOrder(root->rchild);
	}
}

void BinaryTree::PostOrder(Node *root)
{
	if (root != NULL)
	{
		PostOrder(root->lchild);
		PostOrder(root->rchild);
		printf("%c", root->data);
	}
}

void BinaryTree::LevelOrder(Node *root)
{
	Node * queue[1000];
	int front = 0;
	int rear = 1;
	if(root == NULL)
	{
		return;
	}
	queue[front] = root;
	while (front != rear)
	{
		Node *p = queue[front++];
		printf("%c", p->data);
		if(p->lchild != NULL)
		{
			queue[rear++] = p->lchild;
		}
		if (p->rchild != NULL)
		{
			queue[rear++] = p->rchild;

		}
	}


}

int BinaryTree::NodeCount(Node *root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		return 1+NodeCount(root->lchild)+NodeCount(root->rchild);
	}
}


int BinaryTree::BinaryTreeLevel(Node *root)
{
	if (root == NULL)
	{
		return 0;    
	} 
	else
	{
		if (BinaryTreeLevel(root->lchild) > BinaryTreeLevel(root->rchild))
		{
			return 1+BinaryTreeLevel(root->lchild);
		} 
		else
		{
			return 1+BinaryTreeLevel(root->rchild);
		}
	}
}
void main()
{
	Node *root=NULL;
	BinaryTree binaryTree(root);

    printf("\n前序遍历:");
	binaryTree.PreOrder(root);

    printf("\n前序非递归遍历:");
	binaryTree.PreOrderUsingStack(root);

    printf("\n中序遍历:");
	binaryTree.InOrder(root);

    printf("\n后序遍历:");
	binaryTree.PostOrder(root);

    printf("\n层遍历:");
	binaryTree.LevelOrder(root);

    printf("\n结点数:%d\n", binaryTree.NodeCount(root));

    printf("\n层数:%d\n", binaryTree.BinaryTreeLevel(root));
}