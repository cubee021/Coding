#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<vector<int>>& board, vector<vector<bool>>& check)
{
	int n = board.size();
	int m = board[0].size();

	vector<pair<int, int>> dh = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	check[0][0] = true;

	while (!q.empty())
	{
		int i = q.front().first;
		int j = q.front().second;
		q.pop();

		for (auto h : dh)
		{
			int x = i + h.first;
			int y = j + h.second;

			if (x >= 0 && x < n && y >= 0 && y < m)
			{
				if (!check[x][y] && board[x][y] == 1)
				{
					check[x][y] = true;
					q.push({ x, y });

					board[x][y] += board[i][j];
				}
			}
		}

	}
}

int main()
{
	int N, M;
	cin >> N >> M;

	vector<vector<int>> board(N, vector<int>(M, false));
	vector<vector<bool>> check(N, vector<bool>(M, false));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%1d", &board[i][j]);
		}
	}

	BFS(board, check);

	cout << board[N - 1][M - 1];
}