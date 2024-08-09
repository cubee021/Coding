#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, S, M;
    cin >> N >> S >> M;

    vector<int> volume(N+1);
    for (int i = 1; i <= N; i++)
        cin >> volume[i];

    vector<vector<bool>> DP(N+1, vector<bool>(M+1, 0));
    DP[0][S] = true;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= M; j++)
        {
            if (DP[i - 1][j])
            {
                if (j + volume[i] <= M) DP[i][j + volume[i]] = true;
                if (j - volume[i] >= 0) DP[i][j - volume[i]] = true;
            }
        }
    }

    for(int i=M; i>=0; i--)
        if (DP[N][i])
        {
            cout << i;
            return 0;
        }

    cout << -1;
}