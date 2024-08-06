#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int max3(int& a, int& b, int& c)
{
    return max(a, max(b, c));
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> board(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];

    vector<vector<int>> dist(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            if (i == 0 && j == 0)
            {
                dist[i][j] = board[i][j];
                continue;
            }
            else if (i == 0)
            {
                dist[i][j] = dist[i][j-1] + board[i][j];
                continue;
            }
            else if (j == 0)
            {
                dist[i][j] = dist[i-1][j] + board[i][j];
                continue;
            }

            dist[i][j] = max3(dist[i - 1][j], dist[i][j - 1], dist[i - 1][j - 1]) + board[i][j];
        }

    cout << dist[N - 1][M - 1];
}