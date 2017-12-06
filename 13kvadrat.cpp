#include <iostream>
using namespace std;

int rmin = 1000000;

void test(int n, int r)
{
    
    if (r<rmin) 
    if (n==0) 
    rmin=r; 
    else 
    {
        int i,
        j=n;
        do 
        {	
        	i=j; 
        	j=(2*i + n/i/i)/2;} 
        	while (j<i);
      	for (; (i>0) && (i*i+(i+1)*(i+1)>n); i--) 
      	test(n-i*i, r+1);
        	
    }
}

int main()
{   
    int n; cin >> n; cout << "Вводимое число: " << n << endl; 
    test(n, 0);
    cout << "Количество квадратов в разложении: " << rmin << "\n";
    system("pause");
    return 0;
}
