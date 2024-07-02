#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
vector<pair<int, int>> dh = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

void BFS(vector<vector<int>>& new_board, vector<pair<int, int>>& virus)
{
	queue<pair<int, int>> q;

	for (auto v : virus)
		q.push(v);
	
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (auto d : dh)
		{
			int nx = x + d.first;
			int ny = y + d.second;

			if (nx >= 0 && nx < N && ny >= 0 && ny < M)
			{
				if (new_board[nx][ny] == 0)
				{
					new_board[nx][ny] = 2;
					q.push({ nx, ny });
				}
			}
		}
			
	}
	
}

int main()
{
	int answer = 0;
	cin >> N >> M;

	vector<vector<int>> board(N, vector<int>(M, 0));
	vector<pair<int, int>> empty;
	vector<pair<int, int>> virus;
	for(int i=0; i<N ;i++)
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 0)
				empty.push_back({ i, j });

			if (board[i][j] == 2)
				virus.push_back({ i, j });
		}
			
	vector<int> order(empty.size(), 1);
	for (int i = 0; i < 3; i++)
		order[i] = 0;

	do {
		int cnt = 0;

		vector<vector<int>> temp = board;
		for (int i=0; i<order.size(); i++)
		{
			if (order[i] == 0)
			{
				int x = empty[i].first;
				int y = empty[i].second;

				temp[x][y] = 1;
			}
		}

		BFS(temp, virus);

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (temp[i][j] == 0) cnt++;

		answer = max(answer, cnt);

	} while (next_permutation(order.begin(), order.end()));


	cout << answer;
}