#include <iostream> 
#include <algorithm> 
#include <stdio.h> 
using namespace std;

int main() 
{ 
    int c; 
    cin » c; 
    int *a = new int[c + 1]; 
    a[0] = 0; 
    for (int i = 1; i < c + 1; i++) 
    { 
        a[i] = i; 
        for (int j = 1; j*j <= i; j++) 
            a[i] = min(a[i], a[i - j*j]); 
        a[i]++; 
    } 
    cout « a[c] « endl; 

    for (;c;) 
        for (int j = 1; j*j <= c; j++) 
            if (a[c] == a[c - j*j] + 1)
            { 
                cout « j*j«' '; 
                c =c- j*j; 
                break; 
            } 
    return 0; 
}
