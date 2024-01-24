#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<char, int> m;
    
    for(char c : s)
    {
        if(m.find(c) != m.end())
        {
            answer.push_back(m[c]);
            m[c] = 0;
        }
        else
        {
            answer.push_back(-1);
            m.insert({c, 0});
        }
        
        for(auto iter=m.begin(); iter!=m.end(); iter++)
            iter->second++;
    }
    
    return answer;
}