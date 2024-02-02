#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map<char, int> m;
    
    for(string s : keymap)
        for(int i=0; i<s.length(); i++)
        {
            if(m.find(s[i]) != m.end())
            {
                if(m[s[i]] > i+1) m[s[i]] = i+1;
            }
            else
                m[s[i]] = i+1;
        }
    
    for(string s : targets)
    {
        int cnt = 0;
        for(char c : s)
        {
            if(m.find(c) != m.end())
                cnt += m[c];
            else
            {
                cnt = -1;
                break;
            }
        }
        
        answer.push_back(cnt);
    }
    
    return answer;
}