#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<vector<int>> board(N, vector<int>(M));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%1d", &board[i][j]);

	int answer = 0;
	for (int length = 0; length < min(N, M); length++)
	{
		for(int i=0; i<N; i++)
			for (int j = 0; j < M; j++)
			{
				if (i + length >= N || j + length >= M) continue;

				pair<int, int> p1 = { i, j };
				pair<int, int> p2 = { i + length, j };
				pair<int, int> p3 = { i, j + length };
				pair<int, int> p4 = { i + length, j + length };

				if (board[p1.first][p1.second] == board[p2.first][p2.second] &&
					board[p2.first][p2.second] == board[p3.first][p3.second] &&
					board[p3.first][p3.second] == board[p4.first][p4.second])
				{
					answer = max(answer, (length + 1) * (length + 1));
				}
			}
	}

	cout << answer;
}