#include <iostream> #include <algorithm> #include <stdio.h> using namespace std; int main() { int c;cin >> c;
int *a = new int[c + 1]; a[0] =-1; a[1] =-1;a[3] =0;a[4] =-1;for (int i = 5; i < c + 1; i++) { a[i] = -1; for (int j = 0; (j*j+j+3)<= i; j++)
a[i] = min(a[i], a[i - (j*j+j+3)]); if (a[i]!=-1)a[i]++;} //cout << a[c] << endl; 
int k=0;
if (c==3){ cout << 0 << endl;};if ((c==4) or (c==1) or (c==2) or (a[c]==-1)){ cout << -1 << endl;}else {for (;c>0;) for (int j = 0; (j*j+j+3) <= c; j++) if (a[c] == a[c - (j*j+j+3)] + 1){ k=k+j;cout << j*j+j+3 <<' '<< j << " "; c = c - (j*j+j+3); break; } cout << k;}
delete []a;
return 0; }
