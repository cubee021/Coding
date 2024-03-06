#include <iostream>
#include <vector>
using namespace std;

int solution(int& n)
{
	vector<int> DP = { 1, 3 };

	if (n > 1)
	{
		for (int i = 2; i < n; i++)
		{
			DP.push_back((DP[i - 1] + 2 * DP[i - 2]) % 10007);
		}
	}

	return DP[n - 1];
}

int main()
{
	int n;
	cin >> n;

	cout << solution(n);
}