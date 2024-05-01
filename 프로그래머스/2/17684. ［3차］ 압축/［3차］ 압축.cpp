#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> m;
    string temp = "";
    int l=0, dict_idx = 27;
    
    while(l < msg.length())
    {
        temp += msg[l];
        
        if(m.find(temp+msg[l+1]) == m.end())
        {
            if(temp.length() == 1)
                answer.push_back(msg[l] - 64);
            else
                answer.push_back(m[temp]);
            
            m[temp+msg[l+1]] = dict_idx++;
            
            temp = "";
        }
        
        l++;
    }
    
    return answer;
}