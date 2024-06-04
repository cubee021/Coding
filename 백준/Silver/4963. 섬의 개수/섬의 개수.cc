#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<vector<int>>& board, vector<vector<bool>>& check, pair<int, int> cur)
{
	int n = board.size();
	int m = board[0].size();
	vector<pair<int, int>> dh = { {1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };

	queue<pair<int, int>> q;
	q.push({ cur.first, cur.second });
	check[cur.first][cur.second] = true;

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
					q.push({ x, y });
					check[x][y] = true;
				}
			}
		}
	}

}

int main()
{
	int w, h;
	cin >> w >> h;
	while (w != 0 && h != 0)
	{
		int answer = 0;

		vector<vector<int>> board(h, vector<int>(w, false));
		vector<vector<bool>> check(h, vector<bool>(w, false));
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				int a;
				cin >> a;

				board[i][j] = a;
			}
		}

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (!check[i][j] && board[i][j] == 1)
				{
					BFS(board, check, { i, j });
					answer++;
				}
			}
		}

		cout << answer << '\n';
		cin >> w >> h;
	}
}
