#include <iostream>
using namespace std;

struct List
{
	int x;
    List *Next,*Head;
};


void Add(int x, List *&MyList) 
{
	List *temp=new List;
	temp->x=x;
	temp->Next=MyList->Head;
	MyList->Head=temp;
}


void Show(List *MyList)
{
	List *temp=MyList->Head;
	while (temp!=NULL)
	{
		cout<<temp->x<<" ";
		temp=temp->Next;
    }
}


void ClearList(List *MyList)
    {
    	while (MyList->Head!=NULL)
    	{
    		List *temp=MyList->Head->Next;
    		delete MyList->Head;
    		MyList->Head=temp;
    	}
    }

int main()
{


    List *MyList=new List;
    MyList->Head=NULL;
    
    for (int i=0;i<10;i++)
	    Add(i,MyList);
	Show(MyList);

    ClearList(MyList);
    delete MyList->Head;
    delete MyList;
}
