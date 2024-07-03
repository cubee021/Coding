#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
int check[1001][1001][2];
vector<pair<int, int>> dh = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

void BFS(vector<vector<int>>& board)
{
	queue<vector<int>> q;
	q.push({ 0, 0, 0 }); // x, y, bDestroyed
	check[0][0][0] = 1;

	while (!q.empty())
	{
		int x = q.front()[0];
		int y = q.front()[1];
		int destroyed = q.front()[2];
		q.pop();

		for (auto h : dh)
		{
			int nx = x + h.first;
			int ny = y + h.second;

			if (nx >= 0 && nx < N && ny >= 0 && ny < M)
			{
				if (board[nx][ny] == 0 && check[nx][ny][destroyed] == 0)
				{
					check[nx][ny][destroyed] = check[x][y][destroyed] + 1;
					q.push({nx, ny, destroyed});
				}

				if (destroyed == 0 && board[nx][ny] == 1 && check[nx][ny][destroyed+1] == 0)
				{
					check[nx][ny][1] = check[x][y][0] + 1;
					q.push({ nx, ny, 1 });
				}
			}
		}
	}
}

int main()
{
	cin >> N >> M;

	vector<vector<int>> board(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%1d", &board[i][j]);
		}
	}

	BFS(board);

	if (check[N - 1][M - 1][0] != 0 && check[N - 1][M - 1][1] != 0)
		cout << min(check[N - 1][M - 1][0], check[N - 1][M - 1][1]);
	else if (check[N - 1][M - 1][0] != 0)
		cout << check[N - 1][M - 1][0];
	else if (check[N - 1][M - 1][1] != 0)
		cout << check[N - 1][M - 1][1];
	else cout << -1;
}