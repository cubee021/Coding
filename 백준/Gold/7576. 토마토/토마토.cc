#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> ripen;

void BFS(vector<vector<int>>& board, vector<vector<bool>>& check)
{
	int n = board.size();
	int m = board[0].size();
	vector<pair<int, int>> dh = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

	queue<pair<int, int>> q;
	for (auto r : ripen)
	{
		q.push({ r.first, r.second });
		check[r.first][r.second] = true;
	}

	ripen.clear();

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
				if (!check[x][y] && board[x][y] == 0)
				{
					board[x][y] = 1;
					check[x][y] = true;

					ripen.push_back({x, y});
				}
			}
		}

	}

}

int main()
{
	int N, M, answer = 0;
	cin >> N >> M;

	vector<vector<int>> board(M, vector<int>(N, false));
	vector<vector<bool>> check(M, vector<bool>(N, false));

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int a;
			cin >> a;

			board[i][j] = a;
		}
	}

	bool all_ripen = true;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] == 1) ripen.push_back({ i, j });
			if (board[i][j] != 1) all_ripen = false;
		}
	}

	if (all_ripen)
	{
		cout << 0;
		return 0;
	}

	while (ripen.size() != 0)
	{
		BFS(board, check);
		answer++;
	}

	for(int i=0; i<M; i++)
		for(int j=0; j<N; j++)
			if (board[i][j] == 0)
			{
				cout << -1;
				return 0;
			}

	cout << answer - 1;
}