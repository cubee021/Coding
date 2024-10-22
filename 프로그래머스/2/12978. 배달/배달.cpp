#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
using namespace std;

vector<pair<int, int>> cost[51];

void Dijkstra(vector<int>& dist)
{
    priority_queue<pair<int, int>> pq; // total, node
    
    pq.push({0, 1});
    dist[1] = 0;
    
    while(!pq.empty())
    {
        int d = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        for(auto next : cost[cur])
        {
            if(dist[next.first] > dist[cur] + next.second)
            {
                dist[next.first] = dist[cur] + next.second;
                pq.push({dist[next.first], next.first});
            }
        }
    }
}

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    
    for(auto r : road)
    {
        cost[r[0]].push_back({r[1], r[2]});
        cost[r[1]].push_back({r[0], r[2]});
    }
    
    vector<int> dist(N+1, INT_MAX);
    Dijkstra(dist);
    
    for(int i=1; i<=N; i++)
        if(dist[i] <= K) answer++;
        
    return answer;
}