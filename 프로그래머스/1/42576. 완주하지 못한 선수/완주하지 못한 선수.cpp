#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> map;
    
    for(string p : participant)
    {
        if(map.find(p) == map.end())
            map.insert({p, 1});
        else
            map[p]++;
    }
    
    for(string c : completion)
        map[c]--;
    
    for(auto iter=map.begin(); iter!=map.end(); iter++)
        if(iter->second != 0)
            answer = iter->first;
    
    return answer;
}