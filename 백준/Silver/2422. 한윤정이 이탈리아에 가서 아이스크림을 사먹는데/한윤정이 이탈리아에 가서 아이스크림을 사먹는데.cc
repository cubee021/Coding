#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<vector<bool>> mix(N+1, vector<bool>(N+1, true));

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		mix[a][b] = false;
		mix[b][a] = false;
	}

	int answer = 0;
	for (int i=1; i <= N-2; i++)
	{
		for (int j = i+1; j <= N-1; j++)
		{
			if (!mix[i][j]) continue;

			for (int k = j+1; k <= N; k++)
			{
				if (!mix[i][k] || !mix[j][k]) continue;

				answer++;
			}
		}
	}

	cout << answer;
}