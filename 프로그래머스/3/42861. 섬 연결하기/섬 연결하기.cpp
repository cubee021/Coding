#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int parent[101];

int comp(vector<int>& a, vector<int>& b)
{
    return a[2] < b[2];
}

int getParent(int node)
{
    if(parent[node] == node) return node;
    return parent[node] = getParent(parent[node]);
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    for(int i=0; i<n; i++) parent[i] = i;
    
    sort(costs.begin(), costs.end(), comp);
    
    for(int i=0; i<costs.size(); i++)
    {
        int start = getParent(costs[i][0]);
        int end = getParent(costs[i][1]);
        int cost = costs[i][2];
        
        if(start != end)
        {
            answer += cost;
            parent[end] = start;
        }
    }
    
    return answer;
}