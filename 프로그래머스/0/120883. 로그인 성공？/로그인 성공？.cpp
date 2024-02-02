#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) {
   
    map<string, string> m;
    
    for(auto v : db)
        m[v[0]] = v[1];
    
    if(m.find(id_pw[0]) != m.end())
        if(id_pw[1] == m[id_pw[0]])
            return "login";
        else
            return "wrong pw";
    
    return "fail";
}