#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

int main()
{
	vector<pair<int, int>> dh = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, 
								{-1, -1}, {-1, 1}, {1, -1}, {1, 1}, {0, 0} };
	bool answer = false;

	vector<string> board(8);

	for (int i = 0; i < 8; i++)
		cin >> board[i];

	bool check[8][8][9];
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			for (int k = 0; k < 9; k++)
				check[i][j][k] = false;

	queue<tuple<int, int, int>> q; // x, y, time

	q.push({ 7, 0, 0 });
	check[7][0][0] = true;

	while (!q.empty())
	{
		int x, y, t;
		tie(x, y, t) = q.front();
		q.pop();

		if (x == 0 && y == 7) answer = true;
			
		for (auto h : dh)
		{
			int nx = x + h.first;
			int ny = y + h.second;
			int nt = min(t + 1, 8);

			if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8)
			{
				if (nx - t >= 0 && board[nx - t][ny] == '#') continue;
				if (nx - t - 1 >= 0 && board[nx - t - 1][ny] == '#') continue;

				if (!check[nx][ny][nt])
				{
					check[nx][ny][nt] = true;
					q.push({ nx, ny, nt });
				}
			}

		}
	}
	
	cout << (answer ? 1 : 0);
}