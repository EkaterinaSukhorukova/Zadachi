#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
	node* pred;
};

class list
{
	node* tail;
	node* head;
	
public:
	list(): head (NULL), tail (NULL){};
	~list();
	void popend ();
	void popstart ();
	void push (int data);
	void sort();
};
	
void list::push (int data)
{
	node* temp = new node;
	temp -> next = NULL;
	temp -> data = data;
	
	if (head != NULL)
	{
		temp -> pred = tail;
		tail -> next = temp;
		tail = temp;
	}
	else
	{
		temp -> pred = NULL;
		head = tail = temp;
	}
}
	

void list::popend()
{
	node* temp = tail;
	if (temp == NULL)
	{
		cout << "OMG";
	}

	while (temp != NULL)
	{
		cout << temp -> data << " ";
		temp = temp -> pred;
	}
	delete temp;
}
	
void list::popstart()
{
	node* temp = head;
	
	if (temp == NULL)
	{
		cout << "OMG";
	}

	while (temp != NULL)
	{
		cout << temp -> data << " ";
		temp = temp -> next;
	}
	delete temp;
}

void list::sort ()
{	
	node* list = head;
	node* node1;
	node* node2;
		
	for (node1 = list; node1; node1 = node1 -> next)
	{
		for (node2 = list; node2; node2 = node2 -> next)
		{
			if (node1 -> data > node2 -> data)
			{
				int i = node1 -> data;
				node1 -> data = node2 -> data;
				node2 -> data = i;
			}
		}
	}
}

list::~list()
{
	while (head != NULL)
	{
		tail = head -> next;
		delete head;
		head=tail;
	}
}


int main() 
{
	list L;
	L.push (42);
	L.push (18);
	L.push (59);
	L.push (16);
	
	L.popend();
	cout << endl;
	L.popstart();
	cout << endl;
	L.sort();
	L.popend();
	cout << endl;
	L.popstart();
	
	L.~list();
	system ("pause");
	return 0;
}
