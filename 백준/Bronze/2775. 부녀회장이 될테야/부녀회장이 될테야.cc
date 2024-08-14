#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        int k, n;
        cin >> k >> n;

        vector<vector<int>> DP(15, vector<int>(15, 0));
        for (int i = 0; i < 15; i++)
        {
            for (int j = 1; j <= 14; j++)
            {
                if (i == 0) DP[i][j] = j;
                else if (j == 0) DP[i][j] = 1;
                else DP[i][j] = DP[i][j - 1] + DP[i - 1][j];
            }
        }

        cout << DP[k][n] << '\n';
    }
}