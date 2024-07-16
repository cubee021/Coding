#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

vector<pair<int, int>> dh = { {-1, 0}, {1, 0}, {0, -1}, {0, 1},
							{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, 
							{1, -2}, {1, 2}, {2, -1}, {2, 1} };

vector<int> cost = { 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1 };

int dist[200][200][31];

int main()
{
	int K, W, H;
	cin >> K >> W >> H;

	vector<vector<int>> board(H, vector<int>(W));
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			cin >> board[i][j];

	memset(dist, -1, sizeof(dist));

	queue<tuple<int, int, int>> q; // x, y, cnt
	q.push({ 0, 0, 0 });
	dist[0][0][0] = 0;

	while (!q.empty())
	{
		int x, y, cnt;
		tie(x, y, cnt) = q.front();
		q.pop();

		for (int i=0; i<12; i++)
		{
			int nx = x + dh[i].first;
			int ny = y + dh[i].second;
			int ncnt = cnt + cost[i];

			if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
			if (ncnt > K) continue;

			if (dist[nx][ny][ncnt] == -1 && board[nx][ny] == 0)
			{
				q.push({ nx, ny, ncnt });
				dist[nx][ny][ncnt] = dist[x][y][cnt] + 1;
			}

		}
	}

	int answer = 1500001;
	for (int i = 0; i <= K; i++)
	{
		if (dist[H - 1][W - 1][i] == -1) continue;
		answer = min(answer, dist[H - 1][W - 1][i]);
	}

	if (answer == 1500001) cout << -1;
	else cout << answer;
}