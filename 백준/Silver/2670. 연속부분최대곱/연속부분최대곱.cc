#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<double> arr(N+1);
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	vector<double> DP(10001);
	DP[1] = arr[1];

	double answer = DP[1];
	for (int i = 2; i <= N; i++)
	{
		DP[i] = max(arr[i], DP[i - 1] * arr[i]);
		answer = max(answer, DP[i]);
	}

	cout << fixed;
	cout.precision(3);
	cout << answer << endl;
}