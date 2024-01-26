#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> m;
    
    for(auto cloth : clothes)
    {
        if(m.find(cloth[1]) != m.end())
            m[cloth[1]]++;
        else
            m.insert({cloth[1], 2});
    }
    
    for(auto iter=m.begin(); iter!=m.end(); iter++)
        answer *= iter->second;
    
    return answer-1;
}