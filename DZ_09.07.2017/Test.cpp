#include <iostream>
using namespace std;

int main() 
{
	int n;
	cin >> n;
	int ** arr = new int *[n];
	for (int i=0; i<n; i++)
	{
		arr[i] = new int [n];	
		for (int j=0; j<n; j++)
		{
			arr[i][j]=0;
		}
	}
	
	int i=0; 
	int j=0; 
	int k=n*n-1;
	arr[j][i]=n*n;
	
	while (k>0)
	{
	if (arr[j+1][i]==0)
	{
		while (j < n-i-1)
		{
		j=j+1;
		arr[j][i]=k;
		k=k-1;
		}
	}
	

		if (arr[j][i+1]==0) 
		{
			while (i < j )
			{
			i=i+1;
			arr[j][i]=k;
			k=k-1;
			}
		}
	
	

	    	if (arr[j-1][i]==0)
	    	{
	    		while (j > n-i-1)
	    		{
	    		j=j-1;
	    		arr[j][i]=k;
	    		k=k-1;
	    		}
	    	}
	    
	    		if (arr[j][i-1]==0)
	    		{
	    			while (i > j+1)
	    			{
	    			i=i-1;
	    			arr[j][i]=k;
	    			k=k-1;
	    			}
	    		};
	    //	j++;
	    	
	};

	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			cout << arr[j][i] << "\t";
		};
		cout << endl;
	};
	
	for (int i=0; i<n; i++)
	{
		delete (arr[i]);
	}
	
	delete arr[n];
	
	return 0;
}
