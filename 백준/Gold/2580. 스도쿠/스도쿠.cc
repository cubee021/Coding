#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int board[9][9];
vector<pair<int, int>> blank;

bool check(pair<int, int> pos, int val)
{
	for (int i = 0; i < 9; i++)
		if (board[i][pos.second] == val) return false;

	for (int j = 0; j < 9; j++)
		if (board[pos.first][j] == val) return false;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (board[pos.first / 3 * 3 + i][pos.second / 3 * 3 + j] == val) return false;

	return true;
}

bool DFS(int idx = 0)
{
	if (idx == blank.size()) return true;

	int i = blank[idx].first;
	int j = blank[idx].second;

	for (int num = 1; num <= 9; num++)
	{
		if (check(blank[idx], num))
		{
			board[i][j] = num;

			if (DFS(idx + 1)) return true;
		}
	}

	board[i][j] = 0;
	return false;
}

int main()
{
	for(int i=0; i<9; i++)
		for (int j = 0; j < 9; j++)
		{
			cin >> board[i][j];

			if (board[i][j] == 0)
				blank.push_back({ i, j });
		}
	
	DFS();

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			cout << board[i][j] << " ";

		cout << '\n';
	}
}