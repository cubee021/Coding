#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int check(vector<string>& board, int x, int y)
{
	int n = board.size();
	int max_cnt = 0;

	int cnt1 = 1, cnt2 = 1, cnt3 = 1, cnt4 = 1;
	for (int i = 0; i < n - 1; i++)
	{
		if (board[i][y] == board[i + 1][y]) cnt1++; // 아래
		else cnt1 = 1;

		max_cnt = max(max_cnt, cnt1);

		if (y + 1 < n)
		{
			if (board[i][y + 1] == board[i + 1][y + 1]) cnt2++; // 옆 아래
			else cnt2 = 1;

			max_cnt = max(max_cnt, cnt2);
		}

		if (board[x][i] == board[x][i + 1]) cnt3++; // 옆
		else cnt3 = 1;

		max_cnt = max(max_cnt, cnt3);

		if (x + 1 < n)
		{
			if (board[x + 1][i] == board[x + 1][i + 1]) cnt4++; // 아래 옆
			else cnt4 = 1;

			max_cnt = max(max_cnt, cnt4);
		}
	}

	return max_cnt;

}

int main()
{
	int answer = 0;
	int N;
	cin >> N;

	vector<string> board;
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
			if (j + 1 < N)
			{
				swap(board[i][j], board[i][j + 1]);
				int temp = check(board, i, j);
				if (answer < temp) answer = temp;

				swap(board[i][j], board[i][j + 1]);
			}

			if (i + 1 < N)
			{
				swap(board[i][j], board[i + 1][j]);
				int temp = check(board, i, j);
				if (answer < temp) answer = temp;

				swap(board[i][j], board[i + 1][j]);
			}
		}
	}

	cout << answer;
}