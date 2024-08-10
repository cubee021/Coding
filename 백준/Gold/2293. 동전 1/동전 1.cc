#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> value(n+1);
    for (int i = 1; i <= n; i++)
        cin >> value[i];

    vector<int> DP(k+1, 0);
    DP[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = value[i]; j<=k; j++)
        {
            DP[j] += DP[j - value[i]];
        }
    }

    cout << DP[k];
}