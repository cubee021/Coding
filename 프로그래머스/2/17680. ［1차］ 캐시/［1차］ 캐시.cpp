#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque<string> dq;
    
    for(string city : cities)
    {   
        transform(city.begin(), city.end(), city.begin(), ::tolower);
        int i;
        
        for(i=0; i<dq.size(); i++)
        {
            if(city == dq[i])
            {
                dq.push_front(city);
                dq.erase(dq.begin() + i + 1);
            
                answer += 1;
                break;
            }
        }
        
        if(i == dq.size())
        {
            dq.push_front(city);
            if(dq.size() > cacheSize)
                dq.pop_back();
            
            answer += 5;
        }
    }
    
    return answer;
}