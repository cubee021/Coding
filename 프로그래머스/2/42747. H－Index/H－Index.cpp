#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int sum = 0;
    
    for(int i : citations)
        sum += i;
    
    if(sum == 0)
        return 0;
    
    for(int h=0; h<=citations.size(); h++)
    {
        int cnt = 0;
        for(int i : citations)
        {
            if(i >= h)
                cnt++;
        }
        
        if(cnt >= h)
            answer = h;
    }
    
    return answer == 0 ? citations.size() : answer;
}