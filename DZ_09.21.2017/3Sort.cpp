#include <iostream>
using namespace std;

int main() 
{
int n;
cin >> n;
int *ptr = new int [n];

for(int i=0; i<n; i++)
	cin >> (*(ptr+i));
	
int *buf = new int;
                
for(int i = 0; i < n - 1; i++)
{
    for(int j = 0; j < n - i - 1; j++)
        if(*(ptr+j) > *(ptr+j + 1))
        {
                *buf = *(ptr+j);
                *(ptr+j) = *(ptr+j+1);
                *(ptr+j+1) = *buf;
             
        }
} 

for(int i=0; i<n; i++)
	cout << (*(ptr+i));
	
delete []ptr;
	
return 0;
}
