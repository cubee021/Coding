#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>
using namespace std;

int N, M;
bool check[1001][1001];
int area_board[1001][1001];
vector<pair<int, int>> dh = { {1, 0}, {-1, 0},{0, 1}, {0, -1} };

int BFS(vector<vector<int>>& board, int& i, int& j, int & area_idx)
{
	int cnt = 0;

	queue<pair<int, int>> q;
	check[i][j] = true;
	area_board[i][j] = area_idx;
	q.push({i, j});

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		cnt++;

		for (auto h : dh)
		{
			int nx = x + h.first;
			int ny = y + h.second;

			if (nx >= 0 && nx < N && ny >= 0 && ny < M)
			{
				if (!check[nx][ny] && board[nx][ny] == 0)
				{
					q.push({ nx, ny });
					check[nx][ny] = true;
					area_board[nx][ny] = area_idx;
				}
			}
		}

	}

	return cnt;
}

int main()
{
	cin >> N >> M;

	vector<vector<int>> board(N, vector<int>(M, 0));
	vector<pair<int, int>> walls;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			scanf("%1d", &board[i][j]);
			if (board[i][j] == 1)
				walls.push_back({ i, j });
		}
			
	vector<int> area;
	int area_idx = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!check[i][j] && board[i][j] == 0)
			{
				area.push_back(BFS(board, i, j, area_idx));
				area_idx++;
			}
		}
	}

	for (auto w : walls)
	{
		unordered_set<int> set;

		int x = w.first;
		int y = w.second;

		for (auto h : dh)
		{
			int nx = x + h.first;
			int ny = y + h.second;

			if (nx >= 0 && nx < N && ny >= 0 && ny < M)
			{
				if (board[nx][ny] == 0)
					set.insert(area_board[nx][ny]);
			}
		}

		for (auto s : set)
		{
			board[x][y] += area[s-1];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << board[i][j]%10;
		}
		cout << '\n';
	}

}