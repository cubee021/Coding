#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N;
int board[101][101];

void BFS(vector<vector<bool>>& check, int i, int j, int rain)
{
    vector<pair<int, int>> dh = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

    queue<pair<int, int>> q;
    q.push({ i, j });
    check[i][j] = false;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (auto d : dh)
        {
            int nx = x + d.first;
            int ny = y + d.second;

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

            if (check[nx][ny] && board[nx][ny] > rain)
            {
                check[nx][ny] = false;
                q.push({ nx, ny });
            }
        }
    }
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    int answer = 0;
    for (int rain = 0; rain <= 100; rain++)
    {
        int cnt = 0;
        vector<vector<bool>> check(N, vector<bool>(N, true));

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (check[i][j] && board[i][j] > rain)
                {
                    BFS(check, i, j, rain);
                    cnt++;
                }

        answer = max(answer, cnt);
        
        if (cnt == 0) break;
    }

    cout << answer;
}