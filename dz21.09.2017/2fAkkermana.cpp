#include <iostream>

using namespace std;

long fAkkermana(long m, long n) {
    if (m == 0) 
    {
        return n + 1;
    } 
    else 
    {
        if (n > 0) 
        {
            return fAkkermana(m - 1, fAkkermana(m, n - 1));
        } 
        else 
        {
            return fAkkermana(m - 1, 1);
        }
    }
}
int main(void) {
    for (int i = 0; i < 4; i++) 
    {
        for (int j = 0; j < 14; j++) 
        {
            cout << "m = " << i << "\tn = " << j
                << "\tfAkkermana(m, n) = " << fAkkermana(i, j) << endl;
        }
    }
}
