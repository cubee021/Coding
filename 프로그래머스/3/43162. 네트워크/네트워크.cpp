#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

bool check[201];

void BFS(vector<vector<int>>& edge, int idx)
{
    queue<int> q;
    q.push(idx);
    check[idx] = true;
    
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        for(int i = 0; i<edge[cur].size(); i++)
        {
            if(!check[i] && edge[cur][i] == 1)
            {
                q.push(i);
                check[i] = true;
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    memset(check, false, sizeof(check));
    
    for(int i=0; i<n; i++)
    {
        if(!check[i])
        {
            BFS(computers, i);
            answer++;
        }
    }
    
    return answer;
}