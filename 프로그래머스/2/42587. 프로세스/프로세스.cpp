#include <string>
#include <vector>
#include <deque>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    deque<pair<int, int>> dq;
    
    for(int i=0; i<priorities.size(); i++)
        dq.push_back({i, priorities[i]});
    
    while(!dq.empty())
    {
        int i;
        for(i=1; i<dq.size(); i++)
            if(dq.front().second < dq[i].second)
            {
                dq.push_back(dq.front());
                dq.pop_front();
                break;
            }
        
        if(i == dq.size())
        {
            answer++;
            
            if(dq.front().first == location)
                return answer;
            
            dq.pop_front();
        }
            
    }
    
    return answer;
}