#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N;
vector<pair<int, int>> dh = { {-2, -1}, {-2, 1}, {0, -2}, {0, 2}, {2, -1}, {2, 1} };

void BFS(pair<int, int>& start, pair<int, int>& end)
{
	queue<pair<int, int>> q;
	vector<vector<int>> check(N, vector<int>(N, -1));

	q.push(start);
	check[start.first][start.second] = 0;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (end.first == x && end.second == y)
		{
			cout << check[x][y];
			return;
		}

		for (auto d : dh)
		{
			int nx = x + d.first;
			int ny = y + d.second;

			if (nx >= 0 && nx < N && ny >= 0 && ny < N)
			{
				if (check[nx][ny] != -1) continue;

				check[nx][ny] = check[x][y] + 1;
				q.push({ nx, ny });
			}
		}

	}

	cout << -1;
}

int main()
{
	cin >> N;

	pair<int, int> start;
	pair<int, int> end;
	cin >> start.first >> start.second;
	cin >> end.first >> end.second;

	BFS(start, end);
}