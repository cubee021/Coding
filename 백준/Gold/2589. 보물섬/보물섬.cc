#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
string board[51];

int maxDist = 0;

vector<pair<int, int>> dh = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void BFS(int& i, int& j)
{
	queue<pair<int, int>> q;
	q.push({ i, j });

	vector<vector<int>> visited(N, vector<int>(M, 0));
	visited[i][j] = 1;

	while (q.size())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (auto h : dh)
		{
			int nx = x + h.first;
			int ny = y + h.second;

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (board[nx][ny] == 'L' && visited[nx][ny] == 0)
			{
				q.push({ nx, ny });
				visited[nx][ny] = visited[x][y] + 1;
				maxDist = max(maxDist, visited[x][y] + 1);
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

	for (int i = 0; i < N; i++)
		cin >> board[i];
	
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			if(board[i][j] == 'L')
				BFS(i, j);

	cout << maxDist - 1;
	
}