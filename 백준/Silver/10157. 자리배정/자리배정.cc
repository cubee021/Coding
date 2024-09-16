#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int idx = 0;
vector<pair<int, int>> dh = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

int main()
{
	int C, R, K;
	cin >> C >> R >> K;

	if (K > C * R)
	{
		cout << 0;
		return 0;
	}

	vector<vector<int>> board(R, vector<int>(C, 0));
	int x = R-1, y = 0;

	board[x][y] = 1;
	int cnt = 2;

	while (cnt <= K)
	{
		int nx = x + dh[idx].first;
		int ny = y + dh[idx].second;

		if (nx < 0 || nx >= R || ny < 0 || ny >= C || board[nx][ny] != 0)
		{
			idx = (idx + 1) % 4;
			continue;
		}

		board[nx][ny] = cnt++;
		x = nx, y = ny;
	}

	cout << y + 1 << ' ' << R - x;
}