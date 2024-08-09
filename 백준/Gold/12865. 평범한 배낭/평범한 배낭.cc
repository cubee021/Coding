#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> Things; // 무게, 가치
    for (int i = 0; i < N; i++)
    {
        int W, V;
        cin >> W >> V;

        Things.push_back({ W, V });
    }

    vector<vector<int>> DP(N + 1, vector<int>(K + 1, 0));

    for (int i = 0; i < N; i++)
    {
        int weight = Things[i].first;
        int value = Things[i].second;

        for (int w = 0; w <= K; w++)
        {
            if (w - weight >= 0)
                DP[i + 1][w] = max(DP[i + 1][w], DP[i][w-weight] + value);

            DP[i + 1][w] = max(DP[i+1][w], DP[i][w]);
        }
    }
    
    cout << DP[N][K];
}