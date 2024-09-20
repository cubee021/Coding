#include <string>
#include <vector>
#include <queue>
using namespace std;

int max_ = 0;

void BFS(int& n, vector<vector<int>>& node, vector<int>& dist)
{
    vector<bool> check(n+1, true);
    queue<int> q;
    
    q.push(1);
    check[1] = false;
    
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        for(int next : node[cur])
        {
            if(check[next])
            {
                q.push(next);
                check[next] = false;
                
                dist[next] = dist[cur] + 1;
                max_ = max(max_, dist[next]);
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<vector<int>> node(n+1);
    for(auto e : edge)
    {
        node[e[0]].push_back(e[1]);
        node[e[1]].push_back(e[0]);
    }
    
    vector<int> dist(n+1, 0);
    dist[1] = 0;
    
    BFS(n, node, dist);
    
    for(int i=1; i<=n; i++)
        if(dist[i] == max_) answer++;
    
    return answer;
}