#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;

struct Kniga
{
	string avtor;
	string name;
	long int ISBN;
};

long int StrToLInt (string& s)
	{
		 return (long int) atol(s.c_str());
	}
	

void Qsort(Kniga* a, int l, int r)
{
	long int x = a[l+(r-l)/2].ISBN; 
	int j = r; 
	int i = l;
	int t;  
	while (i<=j) 
	{  
		while (a[i].ISBN < x)  
		i++;  
		while (a[j].ISBN > x)  
		j--;  
   
		if (i <= j)  
		{   
			t = a[i].ISBN;   
			a[i].ISBN = a[j].ISBN;  
			a[j].ISBN = t; 
			i++;
			j--;
		}    
	}
	
	if (l < j)
	Qsort(a, i+1, r);
	if (i < r)
	Qsort(a, l, j-1); 
};

int Binary_Search (Kniga* a, int l, int r, long int key)
{
	int mid = 0;
	while (l<=r)
	{
		mid = l+(r-l)/2;
		if (key < a[mid].ISBN)
		{
			Binary_Search (a, l, mid-1, key);
		}
		
		if (key > a[mid].ISBN)
		{
			Binary_Search (a, mid+1, r, key);
		}
		
		if (key = a[mid].ISBN)
		{
			return mid;	
		}
		
	}
	if (l>r)
	return -1;

}

int main() 
{
	int num,k;
	long int x;
	string s1, s;
	
	cin >> num;
	
	Kniga *mas = new Kniga[num];
	for (int i = 0; i < num; i++)
	{

		cin >> mas[i].avtor;
	
		cin >> mas[i].name;

		cin >> s1;
		remove_copy(s1.begin(), s1.end(), back_inserter(s), '-');
		x = StrToLInt (s);;
		
		mas[i].ISBN = x;
	}
	
	Qsort(mas, 0, num-1);
	string savtor, sname;
	cin >> savtor;
	cin >> sname;

	cin >> s1;
	remove_copy(s1.begin(), s1.end(), back_inserter(s), '-');
	x = StrToLInt (s);;
	
	
	k = -1;
	k = Binary_Search (mas, 0, num, x);
	
	if ((k >= 0) and (savtor == mas[k].avtor) and (sname == mas[k].name))
	cout << "Книга в наборе присутствует";
	else 
	cout << "Книги в наборе нет";
	
        
	return 0;
}
