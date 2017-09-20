# Zadachi
#include <iostream>
 
int main()
{
cin >> n;
int a[n];
a[1] = 1;
int i = 2;

while ( i < n*n-1 )
{
 a[i] = a[i-1] + 1;
 int k = 0;
 
   for (int j = i; j < i; j ++ )
    {
     if (a[i] % a[j] = 0)
     {
      k++;
     }
    }
    
    if (k != 0)
    { 
     a[i]++;
    } else
      {
       i++;
      }
}
i=1;
j=n;
k=1;
int b[n][n];
b[i][j] = a[k];
k++;
if (i++ <= n, b[i++][j] == 0)
{
 i++;
 b[i][j] = a[k];
 k++;
} else
  {
   if (j >= 1, b[i][j--] == 0)
   {
    j--;
    b[i][j] = a[k];
    k++;
   } else
     {
      if (i-- >= 1, b[i--][j] == 0)
      {
       i--;
       b[i][j] = a[k];
       k++;
      } else
        {
         if (j++ < n, b[i][j++] == 0)
         {
          j++;
          b[i][j] = a[k];
          k++;
         }
 }
 return 0;
}
