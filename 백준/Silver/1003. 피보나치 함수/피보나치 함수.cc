#include <iostream>
#include <vector>
using namespace std;

pair<int, int> fibonacci(int n)
{
	vector<pair<int, int>> dp{ {1, 0}, {0, 1} };

	if (n > 1)
	{
		for (int i = 2; i <= n; i++)
			dp.push_back({ dp[i - 1].first + dp[i - 2].first, dp[i - 1].second + dp[i - 2].second });
	}

	return dp[n];
}

int main()
{
	int testcase;
	cin >> testcase;

	for (int i = 0; i < testcase; i++)
	{
		int n;
		cin >> n;

		pair<int, int> temp = fibonacci(n);

		cout << temp.first << " " << temp.second << endl;
	}
}