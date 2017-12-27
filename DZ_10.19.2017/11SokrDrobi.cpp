#include <iostream>
using namespace std;

long int phi(long int n) {
	long int result = n;
	for (long int i = 2; i*i <= n; ++i)
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	if (n > 1)
		result -= result / n;
	return result;
}

int main()
{
	long int n;
	cin >> n;
	phi(n);
	cout << n - phi(n);
	
	return 0;
}
