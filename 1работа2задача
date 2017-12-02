#include <iostream>
using namespace std;
 
int main() {
 
	int kvad[51];
	for (int i = 1; i < 51; i++)
	{
	kvad[i] = i*i;	
	};
 
	int n;
	cout << "Введите количество чисел" << endl;
	cin >> n;
	int *mas = new int[n];
 
	for (int i = 0; i < n; i++)
	{
		cin >> mas[i];
	}
 
	int l=0;
	for (int j = 0; j < n; j++)
	{
	for (int i = 0; i < n; i++)	
	{
	if (j != i)
	{
	int pr = mas[j]*mas[i];
		for (int k = 1; k < 51; k++)
		{
			if (pr == kvad[k])
			{
			cout << "Произведение " << mas[j] << " и " << mas[i] << "является точным квадратом" << k << endl;
			l = l+1;
			};
		};
	};
	};
	};
 
	if (l==0)
	{
	cout << "Ни одно из произведений не дает точный квадрат" << endl;
	}
 
 
	return 0;
}
