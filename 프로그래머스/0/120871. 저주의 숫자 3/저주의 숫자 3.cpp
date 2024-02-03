#include <string>
#include <vector>

using namespace std;

bool hasThree(int i)
{
    while(i != 0)
    {
        if(i%10 == 3) 
            return true;
        
        i /= 10;
    }
    
    return false;
}

int solution(int n) {
    int answer = 0;
    
    for(int i=0; i<n; i++)
    {
        answer++;
        
        while(true)
        {
            if(answer%3 == 0 || hasThree(answer))
                answer++;
            else
                break;
        }
    }
    
    return answer;
}