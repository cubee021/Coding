#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

#define MAX_ 3001

int N;
vector<int> edge[MAX_];

int visited[MAX_];

bool cycleFound = false;
int prev_[MAX_];
bool isCycle[MAX_];

// DFS
void getCycle(int cur)
{
    visited[cur] = true;

    for (int next : edge[cur])
    {
        if (cycleFound) return;

        if (visited[next])
        {
            if (prev_[cur] != next)
            {
                cycleFound = true;

                while (cur != next)
                {
                    isCycle[cur] = true;
                    cur = prev_[cur];
                }
                isCycle[next] = true;

                return;
            }
        }
        else
        {
            prev_[next] = cur;
            getCycle(next);
        }
    }
}

void BFS(vector<int>& dist)
{
    queue<int> q;

    for (int i = 1; i <= N; i++)
        if (isCycle[i])
        {
            q.push(i);
            visited[i] = true;
        }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(auto next : edge[cur])
            if (!visited[next])
            {
                dist[next] = dist[cur] + 1;
                visited[next] = true;

                q.push(next);
            }
    }
}

int main()
{
    cin >> N;

    memset(visited, false, sizeof(visited));
    memset(isCycle, false, sizeof(isCycle));

    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;

        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    getCycle(1);

    memset(visited, false, sizeof(visited));
    vector<int> dist(N + 1, 0);

    BFS(dist);

    for (int i=1; i<=N; i++)
        cout << dist[i] << ' ';
}