#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int comp(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> m;
    vector<pair<int, int>> vp;
    
    for(int t : tangerine)
        m.find(t) != m.end() ? m[t]++ : m[t] = 1;
    
    vp.assign(m.begin(), m.end());
    sort(vp.begin(), vp.end(), comp);
    
    int sum = 0;
    for(int i=0; i<vp.size(); i++)
    {
        sum += vp[i].second;
        answer++;
        
        if(sum >= k)
            break;
    }
    
    return answer;
}