#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int x, int y, int n) {
    vector<int> dist(3000001, -1);
    queue<int> q;
    
    q.push(x);
    dist[x] = 0;
    
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        if(cur == y) return dist[cur];
        else if(cur > y) continue;
        
        if(dist[cur+n] == -1)
        {
            q.push(cur + n);
            dist[cur+n] = dist[cur] + 1;
        }
        
        if(dist[cur*2] == -1)
        {
            q.push(cur * 2);
            dist[cur*2] = dist[cur] + 1;
        }
        
        if(dist[cur*3] == -1)
        {
            q.push(cur * 3);
            dist[cur*3] = dist[cur] + 1;
        }
    }
    
    return -1;
}