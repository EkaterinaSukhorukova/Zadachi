#include <iostream>
using namespace std;
 
int prost(unsigned long long a)
{
unsigned long long i;
    if (a == 2)
       return 1;
    if (a == 0 || a == 1 || a % 2 == 0)
       return 0;
  for(i = 3; i*i <= a && a % i; i += 2);
     return i*i > a;
}
 
int main()
{
   long n[1000], a = 1, b, am;
   unsigned long long a_res = 1, ab_res = 1;
   int i = 0, j = 0;
   while(1)
   {
           cin >> n[i];
           if(n[i] == 0)
                   break;
           ++i;
   }
   
   int P[1000] = { 0 };
   for(j = 0; j < i; j++)
   {
         am = n[j];
         if(prost(n[j]) == 1)
         {
                        am = n[j] - 1;
                        cout << am <<endl;
         }
         else
         {
             b = 2;
             a_res = n[j]; ab_res = 1;
             a = 1;
             while(1)
             {
             if(n[j]==1)
                     break;
             for(;;b++)
                       if(n[j]%b==0)
                       {
                                 if(P[a - 1] != b)
                                        {
                                               a_res *= (b-1);
                                               ab_res *= b;
                                               P[a] = b;
                                               a++;
                                        }          
                                 n[j] = n[j]/b;
                                 break;
                        }
             }
                   cout << n[0]-a_res/ab_res << endl;
         }
         
         
         
   }
   system("pause");
   return 0;
}
