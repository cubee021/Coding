#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool check(unordered_map<string, int>& m)
{
    for(auto e : m)
        if(e.second <= 0) return false;
    
    return true;
}

void set_answer(vector<int>& answer, int l, int r)
{
    if(answer[0] == -1) answer = {l+1, r+1};
    
    int r1 = abs(answer[0] - answer[1]);
    int r2 = abs(l - r);
    
    if(r1 > r2)
        answer = {l+1, r+1};
}

vector<int> solution(vector<string> gems) {
    vector<int> answer = {-1, -1};
    unordered_set<string> uset;
    unordered_map<string, int> m;
    
    for(string s : gems)
        uset.insert(s);
    
    int total = uset.size();
    
    int l = 0;
    int r = 0;
    
    m[gems[l]]++;
    
    while(l <= r && l<gems.size())
    {
        if(total == m.size())
        {
            set_answer(answer, l, r);
            
            if(--m[gems[l]] == 0)
                m.erase(gems[l]);
            
            l++;
        }
        else if(r < gems.size()-1)
        {
            r++;
            m[gems[r]]++;
        }
        else 
        {
            if(--m[gems[l]] == 0)
                m.erase(gems[l]);
            
            l++;
        }
    }

    return answer;
}