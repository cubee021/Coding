#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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

	if (!next_permutation(v.begin(), v.end())) cout << -1;
	else
	{
		for (int i : v) cout << i << " ";
	}
}