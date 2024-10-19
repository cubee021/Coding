#include <string>
#include <vector>
#include <cstring>
using namespace std;

int board[1000][1000];
vector<pair<int, int>> dh = { {1, 0}, {0, 1}, {-1, 0} };

vector<int> solution(int n) {
    vector<int> answer;

    memset(board, -1, sizeof(board));

    pair<int, int> cur = { 0, 0 };
    int dir = 0;

    for (int i = 1; i <= n * n; i++)
    {
        board[cur.first][cur.second] = i;

        int nx = cur.first + dh[dir].first;
        int ny = cur.second + dh[dir].second;
        if (dir == 2) ny--;

        if (nx < 0 || nx >= n || ny<0 || ny>=n || board[nx][ny] != -1)
        {
            dir = (dir + 1) % 3;

            nx = cur.first + dh[dir].first;
            ny = cur.second + dh[dir].second;
            if (dir == 2) ny--;
        }

        if (board[nx][ny] != -1) break;
        cur = { nx, ny };
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            answer.push_back(board[i][j]);

    return answer;
}