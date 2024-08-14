#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> stairs(n);
    for (int i = 0; i < n; i++)
        cin >> stairs[i];

    vector<int> DP(n, 0);
    DP[0] = stairs[0];
    DP[1] = stairs[0] + stairs[1];
    DP[2] = max(stairs[0], stairs[1]) + stairs[2];

    for (int i = 3; i < n; i++)
    {
        DP[i] = max(DP[i - 2] + stairs[i], DP[i - 3] + stairs[i - 1] + stairs[i]);
    }

    cout << DP[n-1];
}