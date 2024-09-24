#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;

    queue<int> q;
    unordered_map<int, int> dist;

    q.push(A);
    dist[A] = 1;

    while (!q.empty())
    {
        long long cur = q.front();
        q.pop();

        if (cur == B)
        {
            cout << dist[B];
            return 0;
        }

        if (cur * 2 <= B && dist.find(cur*2) == dist.end())
        {
            dist[cur * 2] = dist[cur] + 1;
            q.push(cur * 2);
        }

        if (cur*10 + 1 <= B && dist.find(cur * 10+1) == dist.end())
        {
            dist[cur*10 + 1] = dist[cur] + 1;
            q.push(cur*10 + 1);
        }

    }

    cout << -1;
}