#include <string>
#include <vector>
#include <set>
using namespace std;

vector<pair<int, int>> dh = { {1, 0}, {0, 1}, {1, 1} };

bool check4(vector<string>& board, int x, int y)
{
    char cur = board[x][y];
    if (cur == '.') return false;

    for (auto d : dh)
    {
        int nx = x + d.first;
        int ny = y + d.second;

        if (board[nx][ny] != cur) return false;
    }

    return true;
}

void move_down(int m, int n, vector<string>& board, set<pair<int, int>>& set)
{
    for (int j = 0; j < n; j++)
        for (int i = m-1; i >= 0; i--)
            if (set.find({ i, j }) != set.end())
            {
                board[i][j] = '.';
            }
            else
            {
                int x = i + 1;

                while (x<m && board[x][j] == '.')
                {
                    board[x][j] = board[x - 1][j];
                    board[x - 1][j] = '.';

                    x++;
                }
            }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    bool go = true;

    while (go)
    {
        set<pair<int, int>> set;

        for (int i = 0; i < m - 1; i++)
            for (int j = 0; j < n - 1; j++)
            {
                if (check4(board, i, j))
                {
                    set.insert({ i, j });
                    set.insert({ i + 1, j });
                    set.insert({ i, j + 1 });
                    set.insert({ i + 1, j + 1 });
                }
            }

        if (set.empty())
        {
            go = false;
            continue;
        }

        answer += set.size();
        move_down(m, n, board, set);
    }
    
    return answer;
}