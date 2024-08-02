#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    
    while(storey > 0)
    {
        int cur = storey%10;
        
        if(cur > 5)
        {
            storey += 10;
            answer += 10-cur;
        }
        else if(cur < 5)
        {
            answer += cur;
        }
        else
        {
            int next = (storey/10) % 10;
            if(next+1 > 5)
            {
                storey += 10;
                answer += 10-cur;
            }
            else
            {
                answer += cur;
            }
        }
        
        storey /= 10;
    }
    
    return answer;
}