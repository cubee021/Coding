#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

int W, H;
vector<pair<int, int>> dh = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int main()
{
	cin >> W >> H;

	vector<string> board(H);
	int sx, sy, ex, ey;
	sx = sy = ex = ey = -1;
	for (int i = 0; i < H; i++)
	{
		cin >> board[i];

		for (int j = 0; j < W; j++)
			if (board[i][j] == 'C')
			{
				if (sx == -1) tie(sx, sy) = { i, j };
				else tie(ex, ey) = { i, j };
			}
	}

	vector<vector<int>> check(H, vector<int>(W, -1));
	queue<pair<int, int>> q;

	q.push({ sx, sy });
	check[sx][sy] = 0;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (auto h : dh)
		{
			int nx = x + h.first;
			int ny = y + h.second;

			while (nx >= 0 && nx < H && ny >= 0 && ny < W)
			{
				if (board[nx][ny] == '*') break;

				if (check[nx][ny] == -1)
				{
					check[nx][ny] = check[x][y] + 1;
					q.push({ nx, ny });
				}

				nx += h.first;
				ny += h.second;
			}
		}
	}

	cout << check[ex][ey] - 1;

}