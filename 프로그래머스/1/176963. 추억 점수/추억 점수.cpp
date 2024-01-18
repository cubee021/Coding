#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> map;
    for(int i=0; i<name.size(); i++)
        map.insert({name[i], yearning[i]});
    
    for(auto& p : photo)
    {
        int temp = 0;
        for(string s : p)
        {
            if(map.find(s) != map.end())
            {
                auto target = map.find(s);
                temp += target->second;
            }
        }
        answer.push_back(temp);
    }
    
    return answer;
}