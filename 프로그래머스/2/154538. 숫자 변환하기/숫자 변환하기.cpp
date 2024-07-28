#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int x, int y, int n) {
    queue<pair<int, int>> q;
    q.push({y, 0});
    
    while(!q.empty())
    {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(cur == x) return cnt;
        
        if(cur - n >= 0)
            q.push({cur-n, cnt+1});
        
        if(cur%2 == 0)
            q.push({cur/2, cnt+1});
        
        if(cur%3 == 0)
            q.push({cur/3, cnt+1});
        
    }
    
    return -1;
}