#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

vector<pair<long long, int>> points;
vector<long long> dist;

long long calc(int a, int b)
{
    return (long long) abs(points[a].first - points[b].first) 
        + (long long) abs(points[a].second - points[b].second);
}

void dijkstra()
{
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, 
        greater<pair<long long, int>>> pq;
    dist[0] = 0;
    pq.push({ 0, 0 });

    while (!pq.empty())
    {
        long long d = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < d) continue;

        for (int i = 0; i < 8; i++)
        {
            long long nd = d + calc(cur, i);
            int next = i;

            if ((cur == 2 && i == 3) || (cur == 3 && i == 2) ||
                (cur == 4 && i == 5) || (cur == 5 && i == 4) ||
                (cur == 6 && i == 7) || (cur == 7 && i == 6))
            {
                nd = d + 10;
            }

            if (dist[next] > nd)
            {
                dist[next] = nd;
                pq.push({ nd, next });
            }
        }
    }
}

int main()
{
    dist.resize(8, LONG_MAX);

    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;

    points.push_back({ sx, sy });
    points.push_back({ ex, ey });

    for (int i = 0; i < 3; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        points.push_back({ x1, y1 });
        points.push_back({ x2, y2 });
    }

    dijkstra();

    cout << dist[1];
}