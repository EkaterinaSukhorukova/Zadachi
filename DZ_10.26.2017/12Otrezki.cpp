#include <iostream>

struct pair {
	int first, second;
};

bool compare(const pair &a, const pair &b) {
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

void sort(pair *array, int len, pair *buffer) {
	if (len <= 1)
		return;
	int mid(len / 2);
	sort(array, mid, buffer);
	sort(array + mid, len - mid, buffer);
	for (int i(0); i < len; ++i)
		buffer[i] = array[i];
	pair *L = buffer, *R = buffer + mid, *Dest = array;
	while (L != buffer + mid or R != buffer + len)
		if (L != buffer + mid and (R == buffer + len or compare(*L, *R)))
			*(Dest++) = *(L++);
		else
			*(Dest++) = *(R++);
}

int binary_search(pair *array, int len, int target) {
	if (!len)
		return 0;
	if (array[len - 1].first <= target)
		return len;
	int L(0), R(len - 1);
	while (L + 1 < R)
	{
		int mid((L + R + 1) / 2);
		if (array[mid].first > target)
			R = mid;
		else
			L = mid;
	}
	return R;
}

#define Array(type, name, size) type *name = new type[size]

int main()
{
	std::ios_base::sync_with_stdio(false);

	int n;
	std::cin >> n;
	pair a[n], buffer[n];

	for (int i(0); i < n; ++i)
		std::cin >> a[i].first >> a[i].second;
	sort(a, n, buffer);

	int next[n], best[n], size[n];

	best[n - 1] = n - 1;
	size[n - 1] = 1;
	next[n - 1] = n;

	for (int i(n - 2); i >= 0; --i) {
		best[i] = best[i + 1];
		size[i] = size[i + 1];
		next[i] = next[i + 1];

		int candidat(i + 1 + binary_search(a + i + 1, n - i, a[i].second));
		if (candidat != n and 1 + size[candidat] > size[i]) {
			size[i] = 1 + size[candidat];
			next[i] = candidat;
			best[i] = i;
		}
	}

	std::cout << size[0] << "\n";
	int current(0);

	while (current != n) {
		std::cout << a[current].first << ' ' << a[current].second << "\n";
		current = next[current];
	}

	delete [] a;
	delete [] buffer;
	delete [] best;
	delete [] size;
	delete [] next;
}
