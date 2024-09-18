#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, D;
int answer = 0;

int dist(pair<int, int> enemy, pair<int, int> archer)
{
	return abs(enemy.first - archer.first) + abs(enemy.second - archer.second);
}

void battle(vector<vector<int>>& board, vector<pair<int, int>>& archers)
{
	bool clear = false;
	int cnt = 0;

	while (!clear)
	{
		for (auto archer : archers)
		{
			vector<vector<pair<int, int>>> ok(N * M + 1);
			int min_dist = N * M + 1;

			for(int j=0; j<M; j++)
				for (int i = N - 1; i >= 0; i--)
				{
					if (board[i][j] != 0)
					{
						int d = dist({ i, j }, archer);
						if (d <= D)
						{
							ok[d].push_back({ i, j });
							min_dist = min(min_dist, d);
						}
					}
				}

			if (min_dist == N * M + 1) continue;

			board[ok[min_dist][0].first][ok[min_dist][0].second]++;
		}
		
		clear = true;
		for(int i = N - 1; i >= 0; i--)
			for (int j = 0; j < M; j++)
			{
				if (board[i][j] > 1)
				{
					cnt++;
					board[i][j] = 0;
				}

				if (board[i][j] == 1) clear = false;

				if (i - 1 >= 0)
					if (board[i-1][j] > 1)
						board[i][j] = 0;
					else
						board[i][j] = board[i-1][j];
				else
					board[i][j] = 0;
			}

	}

	answer = max(answer, cnt);
}

int main()
{
	cin >> N >> M >> D;

	vector<vector<int>> board(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];

	vector<int> check(M, 1);
	for (int i = 0; i < 3; i++)
		check[i] = 0;

	do {
		vector<vector<int>> temp = board;
		vector<pair<int, int>> archers;

		for (int i=0; i<check.size(); i++)
		{
			if (check[i] == 0) archers.push_back({ N, i });
		}

		battle(temp, archers);

	} while (next_permutation(check.begin(), check.end()));

	cout << answer;
}