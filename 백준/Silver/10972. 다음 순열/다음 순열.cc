#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool next_permutation_(vector<int>& v, int N)
{
	int i = N - 1;
	while (i > 0 && v[i - 1] >= v[i]) i--;

	if (i <= 0) return false;

	int j = N - 1;
	while (v[j] <= v[i - 1]) j--;
	swap(v[j], v[i - 1]);

	j = N - 1;
	while (i < j)
	{
		swap(v[i], v[j]);
		i++, j--;
	}

	return true;
}

int main()
{
	int N;
	cin >> N;

	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;

		v.push_back(a);
	}

	if (!next_permutation_(v, N)) cout << -1;
	else
	{
		for (int i : v) cout << i << " ";
	}
}