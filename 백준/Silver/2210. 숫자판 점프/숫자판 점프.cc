#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int board[5][5];
unordered_set<string> answers;

vector<pair<int, int>> dh = { {1, 0}, {-1, 0}, {0, -1}, {0, 1} };

void DFS(pair<int, int> cur, int cnt = 0, string s = "")
{
	if (cnt == 6)
	{
		answers.insert(s);
		return;
	}

	for (auto h : dh)
	{
		int nx = cur.first + h.first;
		int ny = cur.second + h.second;

		if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5)
		{
			char c = board[nx][ny] + '0';
			DFS({ nx, ny }, cnt + 1, s + c);
		}
	}
}

int main()
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> board[i][j];

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
		{
			DFS({ i, j });
		}

	cout << answers.size();
}