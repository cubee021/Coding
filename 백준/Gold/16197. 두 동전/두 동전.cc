#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;

vector<string> board;
vector<int> coin;

int answer = 11;

void BFS(vector<vector<bool>>& check1, vector<vector<bool>>& check2)
{
	vector<pair<int, int>> dh = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

	queue<vector<int>> q;
	q.push({ coin[0], coin[1], coin[2], coin[3], 1 });

	check1[coin[0]][coin[1]] = true;
	check1[coin[2]][coin[3]] = true;

	while (!q.empty())
	{
		int x1 = q.front()[0];
		int y1 = q.front()[1];

		int x2 = q.front()[2];
		int y2 = q.front()[3];

		int cnt = q.front()[4];

		q.pop();

		if (cnt > 10) return;

		for (auto h : dh)
		{
			int nx1 = x1 + h.first;
			int ny1 = y1 + h.second;

			int nx2 = x2 + h.first;
			int ny2 = y2 + h.second;

			if (nx1 >= 0 && nx1 < N && ny1 >= 0 && ny1 < M)
			{
				if (nx2 >= 0 && nx2 < N && ny2 >= 0 && ny2 < M)
				{
					if (board[nx1][ny1] != '#' && board[nx2][ny2] == '#')
						q.push({ nx1, ny1, x2, y2, cnt + 1 });
					else if (board[nx1][ny1] == '#' && board[nx2][ny2] != '#')
						q.push({ x1, y1, nx2, ny2, cnt + 1 });
					else if (board[nx1][ny1] != '#' && board[nx2][ny2] != '#')
						q.push({ nx1, ny1, nx2, ny2, cnt + 1 });

				}
				else
				{
					answer = min(answer, cnt);
				}
			}

			if (nx2 >= 0 && nx2 < N && ny2 >= 0 && ny2 < M)
			{
				if (nx1 < 0 || nx1 >= N || ny1 < 0 || ny1 >= M)
				{
					answer = min(answer, cnt);
				}
			}
		}
	}

}

int main()
{
	cin >> N >> M;

	vector<vector<bool>> check1(N, vector<bool>(M, false));
	vector<vector<bool>> check2(N, vector<bool>(M, false));

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;

		for (int j = 0; j < M; j++)
		{
			if (s[j] == 'o')
			{
				coin.push_back(i);
				coin.push_back(j);
			}
		}

		board.push_back(s);
	}

	BFS(check1, check2);

	if (answer > 10) cout << -1;
	else cout << answer;

}