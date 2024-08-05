#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    unordered_map<string, string> t1; // id, nickname
    vector<pair<string, string>> t2;  // order, id
    
    for(string rec : record)
    {
        string order = "", id = "", nickname = "";
        string temp = "";
        for(char c : rec)
        {
            if(c == ' ')
            {
                if(order == "") order = temp;
                else if(id == "") id = temp;
                
                temp = "";
            }
            else
                temp += c;
        }
        if(id == "") id = temp;
        else nickname = temp;
        
        if(order == "Change")
        {
            t1[id] = nickname;
            continue;
        }
        
        if(order == "Enter")
            t1[id] = nickname;
        t2.push_back({order, id});
    }
    
    for(auto a : t2)
    {
        if(a.first == "Enter")
            answer.push_back(t1[a.second] + "님이 들어왔습니다.");
        else
            answer.push_back(t1[a.second] + "님이 나갔습니다.");
    }
    
    return answer;
}