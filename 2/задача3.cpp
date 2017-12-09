#include <iostream> 
using namespace std;   
struct Date_Name  
{   
int tstart;   
int tend;   
string name; 
};   
void Qsort(Date_Name* a, int l, int r)
{
 int x = a[l+(r-l)/2].tend; 
 int j = l; 
 int i = r; 
 Date_Name t;  
 while (i<=j) 
 {  
 while (a[i].tend<x)  
 i++;  
 while (a[j].tend>x)  
 j--;  
 if (i <= j)  
 {   
 t=a[i];  
 a[i]=a[j];  
 a[j]=t; 
 }  
 i++;
 j--; } 
 if (l < j) 
 Qsort(a, l, j);
 if (i < r)    
 Qsort(a, i, r); 
 } 
  using namespace std;   
  int main() 
  {  
  int n;  
  cin >> n;  
  Date_Name *mas = new Date_Name[n];   
  for (int i = 0; i < n; i++)  
  {   
  cin >> mas[i].tstart;  
  cin >> mas[i].tend; 
  cin >> mas[i].name;   
  };     
  int t;    
  Qsort(mas, 0, n);   
  int k = 0;   
  int i=0;  
  int j=1;  
  for (i=0;i<=n;i++)  
  {  
  if (i>=j)  
  {    
  } 
  else   
  {   
  if (mas[j].tstart >= mas[i].tend)  
  {   
  k = k+1;    
  j++;
   }  
   else  
   {  
   j++; 
   }  
   }   
   };   
   cout << k;  
   return 0;
   } 
