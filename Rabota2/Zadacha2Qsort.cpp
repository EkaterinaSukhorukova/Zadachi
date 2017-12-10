#include <iostream>
using namespace std;

void Qsort(int *a, int n, int l, int r)
{
 int x = a[l+(r-l)/2]; 
 int j = r; 
 int i = l;
 int t;  
 while (i<=j) 
 {  
   while (a[i]<x)  
     i++;  
   while (a[j]>x)  
     j--;  
   
   if (i <= j)  
   {   
     t=a[i];   
     a[i]=a[j];  
     a[j]=t; 
     i++;
     j--;
   }    
 }  
  
  if ((i == 3*n-1) or (j == 3*n-1))
  { 
    return;
  } 
  
  if (j < 3*n-1) 
  {  
    Qsort(a, n, i+1, r);
  }
  
  if (i > 3*n-1) 
  {  
    Qsort(a, n, l, j-1); 
  } 
};

int main() 
{ 
  int n; 
  cin >> n;
  int *a = new int[4*n]; 
  for (int i=0; i < 4*n; i++) 
  {  
    cin >> a[i]; 
  } 
  
  Qsort(a, n, 0, 4*n-1);
  cout << a[3*n-1];  
  return 0;
}
