#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N ,answer = 0;
int W[9]; // 무게

void DFS(vector<int> S, int cur = 0, int cnt = 0)
{
    if (cur == N)
    {
        answer = max(answer, cnt);
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (cur == i) continue;
        if (S[cur] <= 0 || S[i] <= 0)
        {
            DFS(S, cur + 1, cnt);
            continue;
        }

        vector<int> new_S = S;

        new_S[cur] -= W[i];
        new_S[i] -= W[cur];

        int new_cnt = cnt;
        if (new_S[cur] <= 0) new_cnt++;
        if (new_S[i] <= 0) new_cnt++;

        DFS(new_S, cur + 1, new_cnt);
    }
}

int main()
{
    cin >> N;

    vector<int> S(9); // 내구도
    for (int i = 0; i < N; i++)
        cin >> S[i] >> W[i];

    DFS(S);

    cout << answer;
}