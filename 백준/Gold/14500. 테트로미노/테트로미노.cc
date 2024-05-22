#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<vector<pair<int, int>>> tetromino = {
		{{0, 0}, {0, 1}, {0,2}, {0,3}}, // 작대기
		{{0,0}, {1,0}, {2,0}, {3,0}},
		{{0, 0}, {0,1}, {1,0}, {1,1}},// 정사각형
		{{0,0}, {1, 0}, {2, 0}, {2, 1}}, // 니은
		{{0, 0}, {0,1}, {0,2}, {-1, 2}},
		{{0,0}, {0,1}, {1,1}, {2,1}},
		{{0,0}, {1,0}, {0,1}, {0,2}},
		{{0,0}, {1,0}, {2,0}, {2, -1}},
		{{0,0}, {0,1}, {0,2}, {1, 2}},
		{{0,0}, {0,1}, {1,0}, {2,0}},
		{{0,0}, {1, 0}, {1,1}, {1,2}},
		{{0,0}, {1,0}, {1,1}, {2,1}}, // 번개
		{{0,0}, {0,1}, {1,0}, {1,-1}},
		{{0,0}, {1,0}, {1,-1}, {2,-1}},
		{{0,0}, {0,-1}, {1,0}, {1,1}},
		{{0,0}, {0,-1}, {0,1}, {1,0}}, // ㅗ
		{{0,0}, {-1,0}, {1,0}, {0,1}},
		{{0,0}, {-1,0}, {0,-1}, {0,1}},
		{{0,0}, {-1,0}, {0,-1}, {1,0}}
	};

	int answer = 0;
	int N, M;
	cin >> N >> M;

	vector<vector<int>> board(N, vector<int>(M, 0));
	for(int i=0; i<N; i++)
		for (int j = 0; j < M; j++)
		{
			int val;
			cin >> val;

			board[i][j] = val;
		}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < tetromino.size(); k++)
			{
				pair<int, int> p1, p2, p3, p4;

				if (i + tetromino[k][0].first >= 0 && i + tetromino[k][0].first < N && j + tetromino[k][0].second >= 0 && j + tetromino[k][0].second < M)
				{
					p1 = { i + tetromino[k][0].first, j + tetromino[k][0].second };
				}
				else continue;

				if (i + tetromino[k][1].first >= 0 && i + tetromino[k][1].first < N && j + tetromino[k][1].second >= 0 && j + tetromino[k][1].second < M)
				{
					p2 = { i + tetromino[k][1].first, j + tetromino[k][1].second };
				}
				else continue;

				if (i + tetromino[k][2].first >= 0 && i + tetromino[k][2].first < N && j + tetromino[k][2].second >= 0 && j + tetromino[k][2].second < M)
				{
					p3 = { i + tetromino[k][2].first, j + tetromino[k][2].second };
				}
				else continue;

				if (i + tetromino[k][3].first >= 0 && i + tetromino[k][3].first < N && j + tetromino[k][3].second >= 0 && j + tetromino[k][3].second < M)
				{
					p4 = { i + tetromino[k][3].first, j + tetromino[k][3].second };
				}
				else continue;

				int sum = board[p1.first][p1.second] + board[p2.first][p2.second] + board[p3.first][p3.second] + board[p4.first][p4.second];
				answer = max(answer, sum);
			}

		}
	}

	cout << answer;
}