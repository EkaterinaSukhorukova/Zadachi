#include <iostream>
using namespace std;

int Stup(int n, int k)
{
   int sum = 0;
   if (n==1)
      return 1;   
   for (int i=0; i < k; i++)
   {
      if ((n-k+1) > 0)
      {
         sum = sum + Stup ((n-k+i), k);
      }
   }
   return sum;
}

int main() 
{
  int n,k;
  cin >> n >> k;
  int s = Stup (n, k);
  cout << s;
	return 0;
}
