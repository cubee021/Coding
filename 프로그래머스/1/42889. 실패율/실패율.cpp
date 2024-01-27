#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    map<int, float> m;
    multimap<float, int, greater<float>> m_reverse;
    
    for(int i=0; i<N; i++)
        m.insert({i+1, 0.0});
    
    for(int i : stages)
        if(m.find(i) != m.end())
            m[i]++;
    
    int players = stages.size();
    for(auto iter=m.begin(); iter!=m.end(); iter++)
    {
        m_reverse.insert({iter->second/players, iter->first});
        players -= iter->second;
    }
    
    for(auto iter=m_reverse.begin(); iter!=m_reverse.end(); iter++)
        answer.push_back(iter->second);
    
    return answer;
}