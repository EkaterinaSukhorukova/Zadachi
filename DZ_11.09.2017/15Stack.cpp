#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
}

struct stack
{
	node* head = NULL;
	
	void push (int new_data)
	{
		node* temp = new node;
		temp -> data = new_data;
		temp -> next = head;
		head = temp;
	}
	
	int pop ()
	{
		if (head == NULL)
		{
			cout << "OMG";
			return 0;
		}
		node* temp = head;
		head = head -> next;
		int temp_data = temp -> data;
		delete temp;
		return temp_data;
	}

	~stack ()
	{
		while (head != NULL)
		{
			node* temp = head;
			head = head -> next;
			delete temp;
		}
	}
}

int main() 
{
	
	stack S;
	S.push (42);
	S.push (18);
	cout << S.pop()<< S.pop()<< S.pop();
	
	return 0;
}
