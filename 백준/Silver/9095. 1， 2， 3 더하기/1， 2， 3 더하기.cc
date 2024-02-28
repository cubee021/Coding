#include <iostream>
#include <vector>
using namespace std;

int solution(int n)
{
	vector<int> dp = { 1, 2, 4 };

	if(n > 3)
	{
		for (int i = 3; i <= n; i++)
			dp.push_back(dp[i - 3] + dp[i - 2] + dp[i - 1]);
	}

	return dp[n - 1];
}

int main()
{
	int testcase;
	cin >> testcase;

	for (int i = 0; i < testcase; i++)
	{
		int n;
		cin >> n;

		cout << solution(n) << endl;
	}
}