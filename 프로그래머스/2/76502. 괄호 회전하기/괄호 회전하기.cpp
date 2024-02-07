#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string s) {
    int answer = 0;
    
    for(int i=0; i<s.length(); i++)
    {
        stack<int> stack;
        
        for(char c : s)
        {
            if(c == '[' || c == '{' || c == '(')
                stack.push(c);
            else
            {
                if(c == ']' && stack.top() == '[')
                    stack.pop();
                else if(c == '}' && stack.top() == '{')
                    stack.pop();
                else if(c == ')' && stack.top() == '(')
                    stack.pop();
                else
                    stack.push(c);
            }
        }
        
        if(stack.empty())
            answer++;
            
        char temp = s[0];
        s = s.substr(1, s.length()-1);
        s += temp;
        
    }
    
    return answer;
}