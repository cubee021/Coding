#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

int set_alpha(char& cur_s, char cur_n)
{
    int cnt = 0;
    
    if(cur_s != cur_n)
    {
        cnt = min(abs(cur_n-cur_s), 
                    abs(cur_s-'A') + abs('Z'-cur_n) + 1);
            
        cur_s = cur_n;
    }
    
    return cnt;
}

int solution(string name) {
    int n = name.length();
    
    string init = "";
    for(int i=0; i<n; i++)
        init += 'A';
    
    queue<tuple<int, int, string>> q; // cur, cnt, s
    q.push({0, 0, init});
    
    while(!q.empty())
    {
        int cur, cnt;
        string s;
        
        tie(cur, cnt, s) = q.front();
        q.pop();
        
        int new_cnt = cnt + set_alpha(s[cur], name[cur]) + 1;
        
        if(s == name) return new_cnt-1;
        
        if(cur <= 0)
        {
            q.push({n-1, new_cnt, s});
            q.push({cur+1, new_cnt, s});
            continue;
        }
        
        if(cur >= n-1)
        {
            q.push({0, new_cnt, s});
            q.push({cur-1, new_cnt, s});
            continue;
        }
        
        q.push({cur+1, new_cnt, s});
        q.push({cur-1, new_cnt, s});
    }
    
    return 0;
}