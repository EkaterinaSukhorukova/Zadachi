#include <iostream>using namespace std;
void Qsort(int *a, int n, int l, int r){
 int x = a[l+(r-l)/2]; int j = l; int i = r; int t;  while (i<=j) {  while (a[i]<x)  i++;  while (a[j]>x)  j--;  if (i <= j)  {   t=a[i];   a[i]=a[j];   a[j]=t;  }  i++;  j--; }  if (i == 3*n) {  return; }; if (i<3*n) {  Qsort(a, n, l, j); } else {  Qsort(a, n, i, r); }; };
int main() { int n; cin >> n; int *a = new int[4*n];  for (int i=0; i < 4*n; i++) {  cin >> a[i]; }  Qsort(a, n, 0, 4*n);
 cout << a[3*n];  return 0;}
