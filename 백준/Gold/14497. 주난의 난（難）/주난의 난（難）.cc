#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
char board[301][301];

pair<int, int> start, target;

vector<pair<int, int>> dh = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int answer = 0;

void BFS()
{
	queue<pair<int, int>> q;
	bool bFoundTarget = false;

	while(!bFoundTarget)
	{
		vector<vector<int>> visited(N, vector<int>(M, 0));

		q.push(start);
		visited[start.first][start.second] = 1;

		answer++;

		while (q.size())
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (board[x][y] == '#')
			{
				bFoundTarget = true;
				break;
			}

			for (auto h : dh)
			{
				int nx = x + h.first;
				int ny = y + h.second;

				if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
				if (visited[nx][ny] == 1) continue;

				if (board[nx][ny] == '1')
				{
					board[nx][ny] = '0';
					visited[nx][ny] = 1;
					continue;
				}

				q.push({ nx, ny });
				visited[nx][ny] = 1;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> N >> M;

	cin >> start.first >> start.second;
	cin >> target.first >> target.second;

	start.first--;
	start.second--;
	target.first--;
	target.second--;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];

	BFS();

	cout << answer;
}