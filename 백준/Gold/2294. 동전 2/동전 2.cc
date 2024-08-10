#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> value(n+1);
    for (int i = 1; i <= n; i++)
        cin >> value[i];

    vector<int> DP(k+1, 1000000);
    DP[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = value[i]; j<=k; j++)
        {
            DP[j] = min(DP[j], DP[j - value[i]] + 1);
        }
    }

    if (DP[k] < 1000000)
    {
        cout << DP[k];
        return 0;
    }

    cout << -1;
}