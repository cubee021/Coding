#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int answer = 0;

int board[17][17];

void DFS(int i = 0, int j = 1, int dir = 0)
{
	if (i == N-1 && j==N-1)
	{
		answer++;
		return;
	}

	// dir 0 : 가로
	// dir 1 : 세로
	// dir 2 : 대각선
	if (dir == 0)
	{
		int nx = i;
		int ny = j + 1;
		if (nx >= 0 && nx < N && ny >= 0 && ny < N)
			if(board[nx][ny] != 1)
				DFS(nx, ny, 0);

		nx = i + 1;
		ny = j + 1;
		if (nx >= 0 && nx < N && ny >= 0 && ny < N)
			if(board[i+1][j] != 1 && board[i][j+1] != 1 && board[nx][ny] != 1)
				DFS(nx, ny, 2);
	}
	else if (dir == 1)
	{
		int nx = i + 1;
		int ny = j;
		if (nx >= 0 && nx < N && ny >= 0 && ny < N)
			if (board[nx][ny] != 1)
				DFS(nx, ny, 1);

		nx = i + 1;
		ny = j + 1;
		if (nx >= 0 && nx < N && ny >= 0 && ny < N)
			if (board[i + 1][j] != 1 && board[i][j + 1] != 1 && board[nx][ny] != 1)
				DFS(nx, ny, 2);
	}
	else if (dir == 2)
	{
		int nx = i;
		int ny = j + 1;
		if (nx >= 0 && nx < N && ny >= 0 && ny < N)
			if (board[nx][ny] != 1)
				DFS(nx, ny, 0);

		nx = i + 1;
		ny = j;
		if (nx >= 0 && nx < N && ny >= 0 && ny < N)
			if (board[nx][ny] != 1)
				DFS(nx, ny, 1);

		nx = i + 1;
		ny = j + 1;
		if (nx >= 0 && nx < N && ny >= 0 && ny < N)
			if (board[i + 1][j] != 1 && board[i][j + 1] != 1 && board[nx][ny] != 1)
				DFS(nx, ny, 2);
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	DFS();

	cout << answer;
}