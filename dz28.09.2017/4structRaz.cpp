#include <iostream>
using namespace std;

class raz
{
	private:
	int a;
	int b;
	int c;
	int d;
	
	public:
	
	void vvod()
	{
		cout << "Числитель первого числа:" << endl;
		cin >> a;
		cout << "Знаменатель первого числа:" << endl;
		cin >> b;
		cout << "Числитель второго числа:" << endl;
		cin >> c;
		cout << "Знаменатель второго числа:" << endl;
		cin >> d;
	};
	
	void sloz()
	{
		int x = a*d + b*c;
		int x1=x;
		int y = b*d;
		int k=1;
		for (int i=1; i<=y; i++)
		{
			if ((x%i == 0) and (y%i==0))
			{
				x1=x1/i;
				k=k*i;
			}
		}
		y=y/k;
		cout << a << "/" << b << " + " << c << "/" << d << "=" << x1 << "/" << y << endl;
	};
	
	void vichit()
	{
		int x = a*d - b*c;
		int x1=x;
		int y = b*d;
		int k=1;
		for (int i=1; i<=y; i++)
		{
			if ((x%i == 0) and (y%i==0))
			{
				x1=x1/i;
				k=k*i;
			}
		}
		y=y/k;
		cout << a << "/" << b << " - " << c << "/" << d << "=" << x1 << "/" << y << endl;
	};
	
	void ymnoz()
	{
		int x = a*c;
		int x1=x;
		int y = b*d;
		int k=1;
		for (int i=1; i<=y; i++)
		{
			if ((x%i == 0) and (y%i==0))
			{
				x1=x1/i;
				k=k*i;
			}
		}
		y=y/k;
		cout << a << "/" << b << " * " << c << "/" << d << "=" << x1 << "/" << y << endl;
	};
	
	void delen()
	{
		int x = a*d;
		int x1=x;
		int y = b*c;
		int k=1;
		for (int i=1; i<=y; i++)
		{
			if ((x%i == 0) and (y%i==0))
			{
				x1=x1/i;
				k=k*i;
			}
		}
		y=y/k;
		cout << a << "/" << b << " / " << c << "/" << d << "=" << x1 << "/" << y << endl;
	};
	
};

int main() 
{
	setlocale(0, "");
	
	raz c1; 
	
	c1.vvod();
	c1.sloz();
	c1.vichit();
	c1.ymnoz();
	c1.delen();
	
	
	
	system("pause"); 
	return 0;
}
