#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> DP(50001, 0);

    for (int i = 1; i <= n; i++)
    {
        DP[i] = DP[i - 1] + 1;

        for (int j = 1; j * j <= i; j++)
            DP[i] = min(DP[i], DP[i - j * j] + 1);
    }

    cout << DP[n];
}