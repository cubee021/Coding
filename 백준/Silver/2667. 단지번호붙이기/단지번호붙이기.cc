#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N;
vector<pair<int, int>> dh = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

vector<int> answer;

void BFS(vector<vector<int>>& board, int i, int j)
{
	queue<pair<int, int>> q;
	q.push({ i, j });
	board[i][j] = 0;

	int count = 0;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		count++;

		for (pair<int, int> h : dh)
		{
			int nx = x + h.first;
			int ny = y + h.second;

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (board[nx][ny] == 1)
			{
				q.push({ nx, ny });
				board[nx][ny] = 0;
			}
		}
	}

	answer.push_back(count);
}

int main()
{
	cin >> N;

	vector<vector<int>> board(N, vector<int>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%1d", &board[i][j]);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] == 1)
				BFS(board, i, j);
		}

	sort(answer.begin(), answer.end());

	cout << answer.size() <<'\n';

	for (int x : answer)
		cout << x << '\n';
}