#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> dh = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

int main()
{
    int N, T;
    cin >> N >> T;

    pair<int, int> p;

    int x = 0, y = 0;
    int dir = 0;

    vector<vector<int>> board(N, vector<int>(N, 0));
    for (int i = N*N; i >=1; i--)
    {
        board[x][y] = i;
        if (i == T)
        {
            p.first = x;
            p.second = y;
        }

        int nx = x + dh[dir].first;
        int ny = y + dh[dir].second;

        if (nx < 0 || nx >= N || ny < 0 || ny >= N || board[nx][ny] != 0)
            dir = (dir + 1) % 4;

        x += dh[dir].first;
        y += dh[dir].second;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << board[i][j] << ' ';
        cout << '\n';
    }

    cout << p.first+1 << ' ' << p.second+1;
}