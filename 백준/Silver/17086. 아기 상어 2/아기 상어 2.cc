#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
vector<pair<int, int>> dh = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };

int BFS(vector<vector<int>>& board, int i, int j)
{
	vector<vector<int>> dist(N, vector<int>(M, -1));
	queue<pair<int, int>> q;

	q.push({ i, j });
	dist[i][j] = 0;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (board[x][y] == 1)
		{
			return dist[x][y];
		}

		for (auto d : dh)
		{
			int nx = x + d.first;
			int ny = y + d.second;

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

			if (dist[nx][ny] == -1)
			{
				q.push({ nx, ny });
				dist[nx][ny] = dist[x][y] + 1;
			}
		}
	}
}

int main()
{
	cin >> N >> M;

	vector<vector<int>> board(N, vector<int>(M));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];


	int answer = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] == 1) continue;

			answer = max(answer, BFS(board, i, j));
		}
			
	cout << answer;
}