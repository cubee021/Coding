#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int paint(vector<string>& board, int x, int y, char color)
{
    int cnt = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (color != board[x + i][y + j]) cnt++;

            color = color == 'B' ? 'W' : 'B';
        }

        color = color == 'B' ? 'W' : 'B';
    }

    return cnt;
}

int main()
{
    int N, M;
    cin >> N >> M;

    int answer = 64;

    vector<string> board(N);
    for (int i = 0; i < N; i++)
        cin >> board[i];

    for (int i = 0; i <= N - 8; i++)
        for (int j = 0; j <= M - 8; j++)
        {
            answer = min(answer, paint(board, i, j, 'B'));
            answer = min(answer, paint(board, i, j, 'W'));
        }

    cout << answer;
}