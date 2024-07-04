#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, K;
int check[1001][1001][11];

vector<pair<int, int>> dh = { {1, 0}, {-1, 0},{0, 1}, {0, -1} };

void BFS(vector<vector<int>>& board)
{
	queue<vector<int>> q;
	q.push({ 0, 0, 0 }); // x, y, wall
	check[0][0][0] = 1;

	while (!q.empty())
	{
		int x = q.front()[0];
		int y = q.front()[1];
		int w = q.front()[2];
		q.pop();

		for (auto h : dh)
		{
			int nx = x + h.first;
			int ny = y + h.second;

			if (nx >= 0 && nx < N && ny >= 0 && ny < M)
			{
				if (board[nx][ny] == 0 && check[nx][ny][w] == 0)
				{
					check[nx][ny][w] = check[x][y][w] + 1;
					q.push({ nx, ny, w });
				}

				if (board[nx][ny] == 1 && w < K && check[nx][ny][w + 1] == 0)
				{
					check[nx][ny][w + 1] = check[x][y][w] + 1;
					q.push({ nx, ny, w + 1 });
				}
			}
		}
	}
}

int main()
{
	cin >> N >> M >> K;

	vector<vector<int>> board(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%1d", &board[i][j]);

	BFS(board);

	int answer = 100000000;
	for (int i = 0; i <= K; i++)
	{
		if (check[N - 1][M - 1][i] != 0)
			answer = min(answer, check[N - 1][M - 1][i]);
	}

	if (answer == 100000000) cout << -1;
	else cout << answer;
}