#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(int n) {
    string answer = "";
    
    while(n > 0)
    {
        int t = n%3;
        if(t == 0)
        {
            t = 4;
            n--;
        }
        
        answer += (t+'0');
        n/=3;
    }
    
    reverse(answer.begin(), answer.end());
    return answer;
}