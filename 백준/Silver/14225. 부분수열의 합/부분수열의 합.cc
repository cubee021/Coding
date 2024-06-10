#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> S;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;

		S.push_back(a);
	}

	vector<bool> results(2000000, false);
	for (int i = 1; i <= N; i++)
	{
		vector<int> check(N, 1);

		for(int j=0; j<i; j++) check[j] = 0;

		do {
			int sum = 0;

			for (int j = 0; j < N; j++)
				if (check[j] == 0) sum += S[j];

			results[sum] = true;

		} while (next_permutation(check.begin(), check.end()));

	}

	for(int i=1; i<results.size(); i++)
		if (!results[i])
		{
			cout << i;
			break;
		}
}