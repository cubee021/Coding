#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<int> arr(N);
	vector<int> sum(N, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		
		if (i == 0)
		{
			sum[i] = arr[i];
		}
		else
		{
			sum[i] = arr[i] + sum[i - 1];
		}
	}

	for (int m = 0; m < M; m++)
	{
		int i, j;
		cin >> i >> j;
		
		if (i == 1)
			cout << sum[j - 1] << "\n";
		else
			cout << sum[j-1] - sum[i-2] << '\n';
	}
}