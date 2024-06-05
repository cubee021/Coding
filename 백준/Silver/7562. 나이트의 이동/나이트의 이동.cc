#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(int& w, pair<int, int>& start, pair<int, int>& end)
{
	vector<pair<int, int>> dh = { {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1} };

	queue<pair<int, int>> q;
	vector<vector<int>> check(w, vector<int>(w, 1));

	q.push({ start.first, start.second });
	check[start.first][start.second] = 0;

	while (!q.empty())
	{
		int i = q.front().first;
		int j = q.front().second;
		q.pop();

		if (i == end.first && j == end.second)
		{
			cout << check[i][j] << '\n';
			break;
		}

		for (auto h : dh)
		{
			int x = i + h.first;
			int y = j + h.second;

			if (x >= 0 && x < w && y >= 0 && y < w)
			{
				if (check[x][y] == 1)
				{
					q.push({ x, y });
					check[x][y] += check[i][j];
				}
			}
		}
	}
}

int main()
{
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int w;
		pair<int, int> start, end;

		cin >> w;
		cin >> start.first >> start.second;
		cin >> end.first >> end.second;

		BFS(w, start, end);
	}
}