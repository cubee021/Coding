#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> board(20, vector<int>(20));
vector<int> dol_cnt = {0};

vector<pair<int, int>> dh = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void BFS(vector<vector<int>>& area, vector<vector<bool>>& check, int i, int j, int num)
{
    int cnt = 0;

    queue<pair<int, int>> q;
    q.push({ i, j });

    check[i][j] = false;
    area[i][j] = num;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        cnt++;

        for (auto d : dh)
        {
            int nx = x + d.first;
            int ny = y + d.second;

            if(nx>=0 && nx<N && ny>=0 && ny<M)
                if (board[nx][ny] == 2 && check[nx][ny])
                {
                    q.push({ nx, ny });
                    check[nx][ny] = false;
                    area[nx][ny] = num;
                }
        }
    }

    dol_cnt.push_back(cnt);
}

bool ok(vector<vector<int>>& b, vector<vector<int>>& area, int num)
{
    for(int i=0; i<N; i++)
        for (int j = 0; j < M; j++)
            if (area[i][j] == num)
            {
                for (auto d : dh)
                {
                    int nx = i + d.first;
                    int ny = j + d.second;

                    if (nx >= 0 && nx < N && ny >= 0 && ny < M)
                        if (b[nx][ny] == 0)
                            return false;
                }
            }
        
    return true;
}

int main()
{
    int answer = 0;
    cin >> N >> M;

    vector<pair<int, int>> blank;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 0) blank.push_back({ i, j });
        }

    vector<vector<int>> area(N, vector<int>(M, 0));
    vector<vector<bool>> check(N, vector<bool>(M, true));
    int num = 1;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if(board[i][j] == 2 && check[i][j])
            { 
                BFS(area, check, i, j, num);
                num++;
            }
    num--;

    vector<int> pick(blank.size(), 1);
    for (int i = 0; i < 2; i++)
        pick[i] = 0;

    do {
        vector<vector<int>> b = board;

        for (int i = 0; i < pick.size(); i++)
            if (pick[i] == 0) b[blank[i].first][blank[i].second] = 1;

        int sum = 0;
        for (int i = 1; i <= num; i++)
            if (ok(b, area, i)) sum += dol_cnt[i];
        
        answer = max(answer, sum);

    } while (next_permutation(pick.begin(), pick.end()));
       

    cout << answer;
}