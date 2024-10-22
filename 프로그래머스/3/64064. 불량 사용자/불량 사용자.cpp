#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<bool> check(8, true);
set<string> set_; 

bool compare(string& s1, string& s2)
{
    if(s1.length() != s2.length()) return false;
    
    for(int k=0; k<s1.length(); k++)
        if(s1[k] != s2[k] && s1[k] != '*') return false;
    
    return true;
}

void DFS(vector<vector<int>>& match_idx, string temp = "", int idx = 0)
{
    if(idx == match_idx.size())
    {
        sort(temp.begin(), temp.end());
        
        set_.insert(temp);
        return;
    }
    
    for(int i : match_idx[idx])
    {   
        if(check[i])
        {
            string t = temp;
            t += (i+'0');
            
            check[i] = false;
            DFS(match_idx, t, idx + 1);
            check[i] = true;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    vector<vector<int>> match_idx(banned_id.size());
    
    for(int i=0; i<banned_id.size(); i++)
    {
        for(int j=0; j<user_id.size(); j++)
        {
            string s1 = banned_id[i];
            string s2 = user_id[j];
            
            if(compare(s1, s2))
                match_idx[i].push_back(j);     
        }
    }
    
    DFS(match_idx);
    
    return set_.size();
}