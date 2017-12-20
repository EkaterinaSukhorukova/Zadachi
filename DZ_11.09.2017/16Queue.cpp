#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};

struct queue
{
	node* tail = NULL;
	void push (int new_data)
	{
		node* temp = new node;
		temp -> data = new_data;
		node* temp_data = tail;
		if (tail != NULL)
		{
			while (tail -> next != NULL)
			{
				tail = tail -> next;
			}
			tail -> next = temp;
			tail = temp_data; 
		}
		else
		{
			tail = temp;
		}
		temp -> next = NULL;
	}


	int pop()
	{
		if (tail == NULL)
		{
			cout << "OMG";
			return 0;
		}
		node* temp = tail;
		int temp_data = temp -> data;
		tail = tail -> next;
		delete temp;
		return temp_data;
	}

	~queue()
	{
		while (tail != NULL)
		{
			node* temp = tail;
			tail = tail -> next;
			delete temp;
		}
	}
};

int main() 
{
	queue Q;
	Q.push (42);
	Q.push (18);
	cout << Q.pop()<< Q.pop()<< Q.pop();
	Q.~queue();
	system ("pause");
	return 0;
}
