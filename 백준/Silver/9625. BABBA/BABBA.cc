#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int K;
    cin >> K;

    vector<pair<int, int>> DP(46); // A, B
    DP[0] = { 1, 0 };
    DP[1] = { 0, 1 };
    DP[2] = { 1, 1 };

    for (int i = 3; i <= K; i++)
    {
        DP[i] = { DP[i - 2].first + DP[i - 1].first, 
                 DP[i - 2].second + DP[i - 1].second };
    }

    cout << DP[K].first << ' ' << DP[K].second;
}