#include <iostream> 
#include <algorithm> 
#include <stdio.h> 
using namespace std; 

int main() 
{ 
  int c;
  cin >> c;
  int *a = new int[c + 1]; 
  a[0] =1000; 
  a[1] =1000;
  a[3] =0;
  for (int i = 4; i < c + 1; i++) 
  {
    a[i] = 1000; 
    for (int j = 0; (j*j+j+3)<= i; j++)
    {
      if ((i - (j*j+j+3))>0)
      {
        a[i] = min(a[i], a[i - (j*j+j+3)]);
        if (a[i]!=1000)
          a[i]++;
      }
    }
  }  
  
  int k=0;
  if (c == 3)
  { 
    cout << 0 << endl;
  };
  
  if (a[c] == 1000)
  { 
    cout << -1 << endl;
  }
  else 
  {
    for (;c>0;) 
      for (int j = 0; (j*j+j+3) <= c; j++)
      {
        if ((c - (j*j+j+3))>=0)
      	{
          if (a[c] == a[c - (j*j+j+3)] + 1)
          {
            k=k+j;
            c = c - (j*j+j+3); 
            break;
          }
        }
      }
    cout << k;
  }
  
delete []a;
    
return 0; 
}
