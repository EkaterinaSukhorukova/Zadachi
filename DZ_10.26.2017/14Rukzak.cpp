#include <iostream>
using namespace std;

struct object
{
	int v;
	int p;
	bool t;
	void spispred()
	{
		cin >> v;
		cin >> p;
		t = true;
	}
};

int Price (int V, object* spis, int n)
{
	if (V == 0)
	{
		return 0;
	}
	int m = 0;
	int k = -1;
	for (int i = 0; ((i < n) and (spis[i].v <= V)); i++)
	{
		if (spis[i].t)
		{
			spis[i].t = false;
			int r = spis[i].p + Price ((V - spis[i].v), spis, n);
			spis[i].t = true;
			if (r > m)
			{
				m = r;
				k = i;
			}
		}
	}
	if (k != -1)
	{
		cout << m << " ";
	}
	return m;
};

int main() {
	
	int V;
	int price;
	int n;
	object* spis = new object[n];
	cin >> V >> n;
	for (int i = 0; i < n; i++)
	{
		spis[i].spispred();
	}
	cout << Price (V, spis, n);
	system ("pause");
	
	return 0;
}
