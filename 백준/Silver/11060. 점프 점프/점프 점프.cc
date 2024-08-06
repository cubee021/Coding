#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> arr(N, 0);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    vector<int> DP(N, 1001);
    DP[0] = 0;

    for (int i = 0; i < N; i++)
    {
        int jump = arr[i];
        for (int j = 1; j <= jump; j++)
            if (i + j < N)
                DP[i + j] = min(DP[i + j], DP[i] + 1);
    }

    if (DP[N - 1] == 1001)
    {
        cout << -1;
        return 0;
    }

    cout << DP[N - 1];
}