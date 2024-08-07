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
        int N;
        cin >> N;

        vector<int> DP(10001, 0);
        DP[0] = 1;

        for (int i = 1; i <= 3; i++)
            for (int j = 1; j <= N; j++)
                if (j - i >= 0)
                    DP[j] += DP[j - i];

        cout << DP[N] <<'\n';
    }
}