#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    unordered_map<string, int> map;
    
    for(string& order : orders)
        sort(order.begin(), order.end());
        
    for(int len : course)
        for(string order : orders)
        {
            if(len > order.length()) continue;
            
            vector<int> check(order.length(), 1);
            for(int i=0; i<len; i++)
                check[i] = 0;
            
            do{
                string s = "";
                for(int i=0; i<order.length(); i++)
                    if(check[i] == 0) s += order[i];
                
                map[s]++;
                
            }while(next_permutation(check.begin(), check.end()));
        }
    
    vector<vector<pair<int, string>>> count(11);
    for(auto p : map)
        if(p.second >= 2)
            count[p.first.length()].push_back({p.second, p.first});
    
    for(int i : course)
    {
        vector<pair<int, string>> v = count[i];
        if(v.empty()) continue;
        
        sort(v.begin(), v.end(), greater<>());
        
        int prev = v[0].first;
        for(auto e : v)
            if(prev == e.first) answer.push_back(e.second);
            else break;
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}