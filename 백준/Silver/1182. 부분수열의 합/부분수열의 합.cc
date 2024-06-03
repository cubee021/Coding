#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, S, answer = 0;
	cin >> N >> S;

	vector<int> num;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;

		num.push_back(a);
	}

	for (int i = 1; i < (1 << N); i++)
	{
		int sum = 0;

		for (int k = 0; k < N; k++)
			if (i & (1 << k))
			{
				sum += num[k];
			}
		
		if (sum == S) answer++;
	}


	cout << answer;
}