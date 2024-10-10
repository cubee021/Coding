#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

int N, M;

void topology_sort(vector<vector<int>>& graph, vector<int>& inDegree, vector<int>& answer)
{
    queue<int> q;

    for (int i = 1; i <= N; i++)
        if (inDegree[i] == 0) q.push(i);

    for (int i = 0; i < N; i++)
    {
        if (q.empty()) return;

        int cur = q.front();
        q.pop();

        answer[i] = cur;

        for (int next : graph[cur])
            if (--inDegree[next] == 0) q.push(next);
    }
}

int main()
{
    cin >> N >> M;

    vector<vector<int>> graph(N + 1);
    vector<int> inDegree(N+1, 0);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        inDegree[b]++;
    }

    vector<int> answer(N, 0);
    topology_sort(graph, inDegree, answer);
        
    for (int i = 0; i < N; i++)
        cout << answer[i] << ' ';
}