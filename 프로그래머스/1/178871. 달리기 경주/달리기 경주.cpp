#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<string, int> m1;
    map<int, string> m2;
    
    for(int i=0; i<players.size(); i++)
    {
        m1.insert({players[i], i+1}); // 이름 순으로 등수 업데이트
        m2.insert({i+1, players[i]}); // 등수 순으로 이름 업데이트
    }
    
    for(string s : callings)
    {
        string temp = "";
        
        auto iter1 = m1.find(s); // kai, 4 
        auto iter2 = m2.find(iter1->second-1); // 3, poe 
        auto iter3 = m1.find(iter2->second); // poe, 3
        auto iter4 = m2.find(iter3->second+1); // 4, kai 
            
        iter1->second--; // (4->3)
        temp = iter2->second;
        iter2->second = iter1->first; // (poe->kai)
        iter3->second++; // (3->4)
        iter4->second = temp;// (kai->poe)
    }
    
    for(auto iter=m2.begin(); iter!=m2.end(); iter++)
        answer.push_back(iter->second);
    
    return answer;
}