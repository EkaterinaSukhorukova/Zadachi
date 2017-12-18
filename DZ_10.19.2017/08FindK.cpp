#include <iostream>
using namespace std;

void Qsort(int *a, int k, int l, int r)
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
  
  if ((i == k-1) or (j == k-1))
  { 
    return;
  } 
  
  if (j < k-1) 
  {  
    Qsort(a, k, i+1, r);
  }
  
  if (i > k-1) 
  {  
    Qsort(a, k, l, j-1); 
  } 
};

int main() 
{ 
  int n; 
  cin >> n;
  cin >> k:
  int *a = new int[n]; 
  for (int i=0; i < n; i++) 
  {  
    cin >> a[i]; 
  } 
  
  Qsort(a, k, 0, n-1);
  cout << a[k-1];  
  return 0;
}
