#include <iostream>
using namespace std;

int x, y;
int puti (int **arr, int i, int j)
{
	int sum = 0;
	if ((i==x) and (j==y))
		return arr[i][j];
	if (arr[i][j] == 0)
		return 0;
	if (i >= 1)
		sum = sum + puti (arr, i-1, j);
	if (j >= 1)
		sum = sum + puti (arr, i, j-1);
	if ((i >= 1) and (j >= 1))
		sum = sum + puti (arr, i-1, j-1);
	if (i >= 2)
		sum = sum + puti (arr, i-2, j);
	if (j >= 2)
		sum = sum + puti (arr, i, j-2);
	if ((i >= 2) and (j >= 2))
		sum = sum + puti (arr, i-2, j-2);
	
	return sum;
}

int main() 
{
	int n, m, x1, y1;
	cin >> n >> m;
	int ** arr = new int *[n];
	for (int i=0; i<n; i++)
	{
		arr[i] = new int [m];	
		for (int j=0; j<m; j++)
		{
			cin >> arr[i][j];
		}
	}
	
	cin >> x >> y >> x1 >> y1;
	
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			cout << arr[j][i] << "\t";
		}
		cout << endl;
	}
	
	cout << puti (arr, x1, y1) << endl;
	system ("pause");
	return 0;
}
