#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, answer = 2147483647;
	cin >> N;

	vector<int> city;
	for (int i = 0; i < N; i++)
		city.push_back(i);

	vector<vector<int>> cost(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int a;
			cin >> a;

			cost[i][j] = a;
		}
	}
	
	sort(city.begin(), city.end());

	do {
		
		int sum = 0;
		bool pass = true;

		for (int i = 0; i < N; i++)
		{
			if (i == N - 1)
			{
				if (cost[city[i]][city[0]] == 0)
				{
					pass = false;
					break;
				}

				sum += cost[city[i]][city[0]];
			}
			else
			{
				if (cost[city[i]][city[i + 1]] == 0)
				{
					pass = false;
					break;
				}

				sum += cost[city[i]][city[i + 1]];
			}
		}

		if(pass) answer = min(answer, sum);

	} while (next_permutation(city.begin(), city.end()));

	cout << answer;
}