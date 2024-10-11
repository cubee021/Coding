#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

int N, M;
int H, W;
pair<int, int> S, F;
int board[1001][1001];

vector<pair<int, int>> dh = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

bool BFS()
{
    vector<vector<int>> dist(N, vector<int>(M, -1));
    queue<pair<int, int>> q;

    q.push(S);
    dist[S.first][S.second] = 0;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == F.first && y == F.second)
        {
            cout << dist[x][y];
            return true;
        }

        for (auto d : dh)
        {
            int nx = x + d.first;
            int ny = y + d.second;

            if (nx < 0 || nx+H > N || ny < 0 || ny+W > M) continue;

            bool ok = true;
            for (int i = 0; i < H; i++)
                if (board[nx + i][ny] == 1 || board[nx + i][ny + W - 1] == 1)
                {
                    ok = false;
                    break;
                }
            for (int i = 0; i < W; i++)
                if (board[nx][ny + i] == 1 || board[nx + H - 1][ny + i] == 1)
                {
                    ok = false;
                    break;
                }

            if (!ok) continue;

            if (dist[nx][ny] == -1)
            {
                q.push({ nx, ny });
                dist[nx][ny] = dist[x][y] + 1;
            }

        }
    }

    return false;
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];

    cin >> H >> W;
    cin >> S.first >> S.second;
    cin >> F.first >> F.second;

    S.first--, S.second--;
    F.first--, F.second--;

    if (!BFS()) cout << -1;
}