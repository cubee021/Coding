#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
int total_cam = 0;
int answer = 65;
int board[8][8];
vector<vector<vector<vector<int>>>> cctv(8, vector<vector<vector<int>>>(4, vector<vector<int>>(8, vector<int>(8)))); // cctv_num, direction, board

vector<vector<vector<pair<int, int>>>> dh = {
	{{{0, 0}}, {{0, 0}}, {{0, 0}}, {{0, 0}}},
	{{{-1, 0}}, {{1, 0}}, {{0, -1}}, {{0, 1}} },
	{{{-1, 0}, {1, 0}}, {{0, -1}, {0, 1}}, {{-1, 0}, {1, 0}}, {{0, -1}, {0, 1}}},
	{{{-1, 0}, {0, 1}}, {{1, 0}, {0, 1}}, {{1, 0}, {0, -1}}, {{-1, 0}, {0, -1}}},
	{{{-1, 0}, {0, -1}, {0, 1}}, {{-1, 0}, {1, 0}, {0, 1}}, {{1, 0}, {0, -1}, {0, 1}}, {{-1, 0}, {1, 0}, {0, -1}}},
	{{{-1, 0}, {1, 0}, {0, -1}, {0, 1} }, { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }, { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }, { {-1, 0}, {1, 0}, {0, -1}, {0, 1}}}
};

void check_view(vector<vector<int>>& check, int cam_num, int dir_num, int x, int y)
{
	check[x][y] = 1; 

	for (auto h : dh[cam_num][dir_num])
	{
		int nx = x + h.first;
		int ny = y + h.second;

		while (nx >= 0 && nx < N && ny >= 0 && ny < M)
		{
			if (board[nx][ny] == 6) break;
			if (check[nx][ny] != 1) check[nx][ny] = 1;

			nx += h.first;
			ny += h.second;
		}
	}
}

void DFS(vector<vector<bool>>& final, int cur=0)
{
	if (cur == total_cam)
	{
		int cnt = 0;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if(!final[i][j] && board[i][j] != 6) cnt++;

		answer = min(answer, cnt);
		return;
	}

	for (int dir = 0; dir < 4; dir++)
	{
		vector<vector<bool>> temp = final;
		vector<vector<int>> cur_cctv = cctv[cur][dir];

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (cur_cctv[i][j] == 1) temp[i][j] = true;

		DFS(temp, cur + 1);
	}
}

int main()
{
	cin >> N >> M;

	vector<pair<int, int>> cam_loc;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
			if (board[i][j] >= 1 && board[i][j] <= 5)
			{
				cam_loc.push_back({ i, j });
				total_cam++;
			}
		}

	for (int i=0; i<total_cam; i++)
	{
		int cam_num = board[cam_loc[i].first][cam_loc[i].second];

		for (int dir = 0; dir < 4; dir++)
		{
			vector<vector<int>> check(8, vector<int>(8, 0));

			check_view(check, cam_num, dir, cam_loc[i].first, cam_loc[i].second);

			cctv[i][dir] = check;
		}
	}

	vector<vector<bool>> final(N, vector<bool>(M, false));
	DFS(final);

	cout << answer;
}