#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, T;

void set_dist(vector<vector<int>>& city, vector<vector<int>>& dist)
{
    for (int i = 1; i <= N-1; i++)
    {
        for (int j = i + 1; j <= N; j++)
        {
            int d = abs(city[i][1] - city[j][1]) + abs(city[i][2] - city[j][2]);

            if (city[i][0] == 1 && city[j][0]) 
                d = min(d, T);

            dist[i][j] = d;
            dist[j][i] = d;
        }
    }
}

void floyd_warshall(vector<vector<int>>& dist)
{
    for(int k=1; k<=N; k++) // 경유
        for (int i = 1; i <= N; i++) // 시작
            for (int j = 1; j <= N; j++) // 도착
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
}

int main()
{
    cin >> N >> T;

    vector<vector<int>> city(N + 1, vector<int>(3));
    for (int i = 1; i <= N; i++)
        cin >> city[i][0] >> city[i][1] >> city[i][2];

    vector<vector<int>> dist(N + 1, vector<int>(N + 1, 1000000));
    set_dist(city, dist);

    floyd_warshall(dist);

    int M;
    cin >> M;
    for (int m = 0; m < M; m++)
    {
        int A, B;
        cin >> A >> B;

        cout << dist[A][B] << '\n';
    }
}