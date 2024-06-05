#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<pair<int, int>> dh = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
vector<vector<int>> dist(51, vector<int>(51, 0));

bool DFS(vector<string>& board, vector<vector<bool>>& check, pair<int, int> cur, int cnt = 0)
{
	int x = cur.first;
	int y = cur.second;

	if (check[x][y]) return cnt - dist[x][y] >= 4;

	check[x][y] = true; dist[x][y] = cnt;

	for (auto h : dh)
	{
		int nx = x + h.first;
		int ny = y + h.second;

		if (nx >= 0 && nx < N && ny >= 0 && ny < M)
			if (board[nx][ny] == board[x][y])
				if (DFS(board, check, { nx, ny }, cnt + 1)) return true;
	}

	return false;
}

int main()
{
	cin >> N >> M;

	vector<string> board;
	vector<vector<bool>> check(N, vector<bool>(M, false));
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;

		board.push_back(s);
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (!check[i][j])
			{
				if (DFS(board, check, { i, j }))
				{
					cout << "Yes";
					return 0;
				}
			}

	cout << "No";
}