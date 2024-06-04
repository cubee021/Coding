#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> answer;

void BFS(vector<string>& board, vector<vector<bool>>& check, pair<int, int> cur)
{
	int n = board.size();
	vector<pair<int, int>> dh = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

	queue<pair<int, int>> q;
	q.push({ cur.first, cur.second });
	check[cur.first][cur.second] = true;

	int cnt = 0;
	while (!q.empty())
	{
		int i = q.front().first;
		int j = q.front().second;
		cnt++;

		q.pop();

		for (auto h : dh)
		{
			int x = i + h.first;
			int y = j + h.second;

			if (x >= 0 && x < n && y >= 0 && y < n)
			{
				if (!check[x][y] && board[x][y] == '1')
				{
					q.push({ x, y });
					check[x][y] = true;
				}
			}
		}
	}

	answer.push_back(cnt);
}

int main()
{
	int N;
	cin >> N;

	vector<string> board;
	vector<vector<bool>> check(N, vector<bool>(N, false));
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;

		board.push_back(s);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!check[i][j] && board[i][j] == '1')
				BFS(board, check, {i, j});
		}
	}
	
	cout << answer.size() << '\n';
	sort(answer.begin(), answer.end());
	for (int i : answer)
	{
		cout << i << '\n';
	}

}