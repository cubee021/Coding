#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<vector<bool>> friends(N + 1, vector<bool>(N+1, false));
	vector<int> count(N + 1, 0);

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		friends[a][b] = true;
		friends[b][a] = true;

		count[a]++;
		count[b]++;
	}

	int answer = -1;
	for(int i=1; i<=N-2; i++)
		for (int j = i + 1; j <= N - 1; j++)
		{
			if (!friends[i][j]) continue;

			for (int k = j + 1; k <= N; k++)
			{
				if (friends[i][k] && friends[j][k])
				{
					int sum = count[i] + count[j] + count[k] - 6;
					if (answer == -1 || answer > sum)
						answer = sum;
				}
			}
		}

	cout << answer;
}