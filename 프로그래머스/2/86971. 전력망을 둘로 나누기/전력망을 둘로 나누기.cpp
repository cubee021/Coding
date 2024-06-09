#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int cnt = 0;

void DFS(vector<vector<int>>& edge, vector<bool>& check, int idx)
{
    check[idx] = true;
    cnt++;
    
    for(int next : edge[idx])
    {
        if(!check[next])
        {
            DFS(edge, check, next);
        }
    }
    
    return;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 101;
    
    for(int t=0; t<wires.size(); t++)
    {
        vector<vector<int>> edge(n+1, vector<int>());
        vector<bool> check(n+1, false);
        
        for(int i=0; i<wires.size(); i++)
        {
            if(i != t)
            {
                int v1 = wires[i][0];
                int v2 = wires[i][1];
        
                edge[v1].push_back(v2);
                edge[v2].push_back(v1);
            }
        }
        
        vector<int> results;
        for(int i=1; i<=n; i++)
        {
            if(!check[i])
            {
                DFS(edge, check, i);
                results.push_back(cnt);
                
                cnt = 0;
            }
        }
        
        answer = min(answer, abs(results[0] - results[1]));
        if(answer == 0) break;
    }
    
    return answer;
}