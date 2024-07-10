#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

int n;
vector<pair<int, int>> dh = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

tuple<int, int, int> BFS(vector<vector<int>>& board, int x, int y, int size)
{
	vector<tuple<int, int, int>> answer; // dist, x, y
	vector<vector<int>> check(n, vector<int>(n, -1));

	queue<pair<int, int>> q;
	q.push({ x, y });
	check[x][y] = 0;

	while (!q.empty())
	{
		tie(x, y) = q.front();
		q.pop();

		for (auto h : dh)
		{
			int nx = x + h.first;
			int ny = y + h.second;

			if (nx >= 0 && nx < n && ny >= 0 && ny < n)
			{
				if (check[nx][ny] == -1)
				{
					bool ok = false;
					bool eat = false;

					if (board[nx][ny] == 0)
						ok = true;
					else if (board[nx][ny] < size)
						ok = eat = true;
					else if (board[nx][ny] == size)
						ok = true;

					if (ok)
					{
						q.push({ nx, ny });
						check[nx][ny] = check[x][y] + 1;

						if (eat)
							answer.push_back({ check[nx][ny], nx, ny });
					}
				}
				
			}
		}
	}

	if (answer.empty()) return { -1, -1, -1 };

	sort(answer.begin(), answer.end());
	return answer[0];

}

int main()
{
	cin >> n;

	vector<vector<int>> board(n, vector<int>(n, 0));
	int x, y;
	for(int i=0; i<n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];

			if (board[i][j] == 9)
			{
				tie(x, y) = { i, j };
				board[i][j] = 0; // 상어 칸은 물고기 없음
			}
		}

	int answer = 0;
	int size = 2;
	int exp = 0;
	while (true)
	{
		int nx, ny, dist;
		tie(dist, nx, ny) = BFS(board, x, y, size);

		if (dist == -1) break;

		board[nx][ny] = 0;
		answer += dist;
		exp++;

		if (size == exp)
		{
			size++;
			exp = 0;
		}
		tie(x, y) = { nx, ny };
	}

	cout << answer;

}