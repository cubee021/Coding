#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int solution(vector<vector<int>> lines) {
    int answer = 0;
    map<int, int> m;
    
    vector<int> starts;
    vector<int> ends;
    
    for(auto l : lines)
    {
        starts.push_back(l[0]);
        ends.push_back(l[1]);
    }
    
    int max = *max_element(starts.begin(), starts.end());
    int min = *min_element(ends.begin(), ends.end());
    
    for(int i=min; i<=max; i++)
        m.insert({i, 0});
    
    for(auto l : lines)
        for(int i=l[0]; i<l[1]; i++)
            m[i]++;
    
    for(auto iter=m.begin(); iter!=m.end(); iter++)
        if(iter->second > 1)
            answer++;
    
    return answer;
}