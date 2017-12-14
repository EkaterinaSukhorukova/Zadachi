#include <iostream>
using namespace std;

struct Kniga
{
	string avtor;
	string name;
	int ISBN;
};

void Qsort(Kniga* a, int l, int r)
{
	int x = a[l+(r-l)/2].ISBN; 
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

int Binary_Search (Kniga* a, int l, int r, int key)
{
	int mid = 0;
	while (1)
	{
		mid = l+(r-l)/2;
		if (key < a[mid].ISBN)
		{
			Binary_Search (a, l, r, int key)
		}
		
		if (key > a[mid].ISBN)
		{
			l = mid + 1;
		}
		
		if (key = a[mid].ISBN)
		{
			return mid;	
		}
		
		if (l >= r)
		{
			return -1;	
		}
		
	}
}

int main() 
{
	int num,x,x1,x2,x3,x4,k;
//	cout << "Введите количество книг в наборе" << endl;
	cin >> num;
	
	Kniga *mas = new Kniga[num];
	for (int i = 0; i < num; i++)
	{
	//	cout << "Введите имя автора";
		cin >> mas[i].avtor;
	//	cout << "Введите название книги";
		cin >> mas[i].name;
	//	cout << "Введите ISBN (3-1-2-6)";
		cin >> x1 >> x2 >> x3 >> x4;
		x = x1 * 1000000000 + x2 * 100000000 + x3 * 1000000 + x4;
		mas[i].ISBN = x;
	}
	
	Qsort(mas, 0, num-1);
	
	string savtor, sname;
	// cout << "Введите имя автора";
	cin >> savtor;
	// cout << "Введите название книги";
	cin >> sname;
	// cout << "Введите ISBN";
	cin >> x1 >> x2 >> x3 >> x4;
	x = x1 * 1000000000 + x2 * 100000000 + x3 * 1000000 + x4;
	
	k = -1;
	k = Binary_Search (mas, 0, num, x);
	
	if ((k >= 0) and (savtor == mas[k].avtor) and (sname == mas[k].name))
	cout << "Книга в наборе присутствует";
	else 
	cout << "Книги в наборе нет";
	
        
	return 0;
}
