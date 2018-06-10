#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s;
    cout <<"enter function \n";
    cin >> s;
    int m;
    cout <<"enter number \n";
    cin >> m;
    vector<char> vec(s.size());
    for(int i=0;i<s.size();i++){
        vec[i]=s[i];
    }
    auto x=[vec,m]{
       int n=0;
       while(n==0){
           for(int i=0;i<vec.size();i++){
               for(int k=i+1;k<vec.size();k++){
                   if(vec[k]=="(")
                       i=k;
                   if(vec[k]==")"){
                       int h,s=0;
                       int g=1;
                       int t=1;
                       for(int j=k-1;k>i;j--){
                           if(atoi(vec[j])>47 && atoi(vec[j])<58){
                               h+=atoi(vec[j])*t
                               t*=10;
                               s++;
                           }
                           if(vec[j]=="*"){
                               g*=h;
                               h=0;
                               t=1;
                           }
                           if(vec[j]=="+"){
                               for(int r=j+s;r>=j;j--){
                                   if(g!=0){
                                       ver[j]==g%10;
                                       g=g/10;
                                   }
                                   else
                                       vec[r]=".";
                               }
                               g=1;
                               h=0;
                               t=1;
                           }
                           h=0;
                           for(int j=k-1;k>i;j--){
                               if(atoi(vec[j])>47 && atoi(vec[j])<58){
                                   h+=atoi(vec[j])*t
                                   t*=10;
                                   s++;
                               }
                               if(vec[j]=="+"){
                                   
                                   g+=h;
                                   h=0;
                                   t=1;
                               }
                           }
                       }
                   }
               }
           }
       }
    };

};
