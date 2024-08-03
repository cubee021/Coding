#include <string>
#include <vector>
#include <deque>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int n = number.size()-k;
    deque<char> dq;
    for(char c : number)
    {
        while(!dq.empty() && c > dq.back())
        {
            if(k <= 0) break;
            
            dq.pop_back();
            k--;
        }
        
        dq.push_back(c);
        if(dq.size() > n)
        {
            dq.pop_back();
            k--;
        }
    }
    
    while(!dq.empty())
    {
        answer += dq.front();
        dq.pop_front();
    }
    
    return answer;
}