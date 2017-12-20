#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};

struct deque
{
	node* tail = NULL;
	node* head = NULL;
	
	void pushback (int new_data)
	{
		node* temp = new node;
		temp -> data = new_data;
		node* temp_data = tail;
		if (tail != NULL)
		{
			tail = temp;
			temp_data -> next = tail; 
		}
		else
		{
			tail = temp;
			head = temp;
		}
		temp -> next = NULL;
	}
	
	void pushfront (int new_data)
	{
		node* temp = new node;
		temp -> data = new_data;
		node* temp_data = head;
		if (head != NULL)
		{
			head = temp;
			head -> next = temp_data; 
		}
		else
		{
			head = temp;
			tail = temp;
			head -> next = NULL;
		}
	}	

	int pop()
	{
		if (head == NULL)
		{
			cout << "OMG";
			return 0;
		}
		int temp_data = head -> data;
		node* temp = head;
		head = head -> next;
		delete temp;
		return temp_data;
	}

	~deque()
	{
		while (head != NULL)
		{
			node* temp = head;
			head = head -> next;
			delete temp;
		}
	}
};

int main() 
{
	deque D;
	D.pushback (42);
	D.pushback (18);
	D.pushfront (59);
	D.pushfront (16);
	cout << D.pop() << D.pop() << D.pop() << D.pop() << D.pop();
	D.~deque();
	system ("pause");
	return 0;
}
