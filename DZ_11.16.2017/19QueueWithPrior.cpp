#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
	int prior;
};

struct queue
{
	node* tail = NULL;
	void push (int new_data, int prioritet)
	{
		node* temp = new node;
		temp -> data = new_data;
		temp -> prior = prioritet;
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
	
	node* min()
	{
		node* min = new node;
		min -> next = tail;
		node* temp = tail;
		while (temp -> next != NULL)
		{
			if (min -> next -> prior < temp -> next -> prior)
			{
				min = temp;
			}
			temp = temp -> next;
		}
		return min;
	}
	
	int pop()
	{
		if (tail == NULL)
		{
			cout << "OMG";
			return 0;
		}
		node* plac;
		int temp_data;
		node* temp = min();
		temp_data = temp ->next -> data;
		plac = temp -> next;
		if (plac == tail)
		{
			if (tail -> next != NULL)
			{
				tail = tail -> next;
			}
			else
			{
				tail = NULL;
			}
		}
		else
		{
			if (plac != NULL)
			{
				temp -> next = plac -> next;
			}
			else
			{
				temp -> next = NULL;
			}
		}
		delete plac;
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
	Q.push (52,3);
	Q.push (15,5);
	Q.push (29,1);
	Q.push (60,2);
	Q.push (2,4);
	cout << Q.pop() << " " << Q.pop() << " " << Q.pop() << " " << Q.pop() << " " << Q.pop() << " ";
	Q.~queue();
	system ("pause");
	return 0;
}
