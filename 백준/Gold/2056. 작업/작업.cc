#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

int N;

void Topology_sort(vector<vector<int>>& graph, vector<int>& inDegree, vector<int>& time,
    vector<int>& results)
{
    queue<int> q;

    for (int i = 1; i <= N; i++)
    {
        if (inDegree[i] == 0) q.push(i);
        results[i] = time[i];
    }

    for (int i = 0; i < N; i++)
    {
        if (q.empty()) return;

        int cur = q.front();
        q.pop();

        for (int next : graph[cur])
        {
            results[next] = max(results[next], results[cur] + time[next]);

            if (--inDegree[next] == 0)
                q.push(next); 
        }
    }
}

int main()
{
    cin >> N;

    vector<vector<int>> graph(N+1);
    vector<int> inDegree(N + 1, 0);
    vector<int> time(N + 1, 0);

    for (int i = 1; i <= N; i++)
    {
        cin >> time[i];

        int n;
        cin >> n;

        for (int j = 0; j < n; j++)
        {
            int b;
            cin >> b;

            graph[b].push_back(i);
            inDegree[i]++;
        }
    }
    
    vector<int> results(N + 1, 0);
    Topology_sort(graph, inDegree, time, results);

    cout << *max_element(results.begin(), results.end());
}