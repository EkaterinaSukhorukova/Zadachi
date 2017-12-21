#include <iostream>
using namespace std;
 
struct Node
{
	int x;
	Node *l,*r;
};
 
void show(Node *&Tree)
{
	if (Tree!=NULL)
	{
		show(Tree->l);
		cout<<Tree->x;
		show(Tree->r);
	}
}

void del(Node *&Tree)
{
	if (Tree!=NULL)
	{
		del(Tree->l);
		del(Tree->r);
		delete Tree;
		Tree = NULL;
	}
}
 
void add_node(int x,Node *&MyTree)
{
	if (NULL==MyTree)
	{
		MyTree=new Node;
		MyTree->x=x;
		MyTree->l=MyTree->r=NULL;
	}
 
	if (x<MyTree->x)
	{
		if (MyTree->l!=NULL) 
			add_node(x,MyTree->l);
		else
		{
			MyTree->l=new Node;
			MyTree->l->l=MyTree->l->r=NULL;
			MyTree->l->x=x;
		}
	}
 
	if (x>MyTree->x)
	{
		if (MyTree->r!=NULL) 
			add_node(x,MyTree->r);
		else
		{
			MyTree->r=new Node;
			MyTree->r->l=MyTree->r->r=NULL;
			MyTree->r->x=x;
		}
	}
}
 
int main()
{
	Node *Tree=NULL;
	int sum = 0;
	for (int i=9;i>0;i--)
	{
		add_node(i,Tree);
		sum = sum + i;
	}
	show(Tree);
	cout << '\n';
	cout << "Sum = " << sum;
	del(Tree);
}
