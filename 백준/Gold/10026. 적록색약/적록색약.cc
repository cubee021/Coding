#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N;
vector<pair<int, int>> dh = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

bool same(bool& cblind, char c1, char c2)
{
	if (c1 == c2)
		return true;
	else
		if (cblind)
		{
			if (c1 == 'R' && c2 == 'G') return true;
			else if (c1 == 'G' && c2 == 'R') return true;
		}

	return false;
}

void BFS(vector<string>& board, vector<vector<bool>>& check, int i, int j, bool cblind)
{
	queue<pair<int, int>> q;

	q.push({ i, j });
	check[i][j] = true;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		char cur = board[x][y];

		q.pop();

		for (auto h : dh)
		{
			int nx = x + h.first;
			int ny = y + h.second;

			if (nx >= 0 && nx < N && ny >= 0 && ny < N)
			{
				char next = board[nx][ny];

				if (!check[nx][ny] && same(cblind, cur, next))
				{
					check[nx][ny] = true;
					q.push({ nx, ny });
				}
			}
		}
	}

}

int main()
{
	cin >> N;

	vector<string> board(N);
	for (int i = 0; i < N; i++)
		cin >> board[i];

	for (int cblind = 0; cblind < 2; cblind++)
	{
		vector<vector<bool>> check(N, vector<bool>(N, false));
		int cnt = 0;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (!check[i][j])
				{
					BFS(board, check, i, j, cblind);
					cnt++;
				}

		cout << cnt << " ";
	}
}