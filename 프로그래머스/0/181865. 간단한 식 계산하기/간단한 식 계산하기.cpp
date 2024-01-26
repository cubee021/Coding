#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string binomial) {
    stack<int> num;
    
    string temp = "";
    string op = "";
    for(char c : binomial)
    {
        if(c == ' ')
        {
            if(temp=="+" || temp=="-" || temp=="*")
                op = temp;
            else
                num.push(stoi(temp));
            
            temp = "";
        }
        else
            temp+=c;
    }
    num.push(stoi(temp));
    
    int b = num.top();
    num.pop();
    int a = num.top();
    
    if(op == "+")
        return a+b;
    else if(op == "-")
        return a-b;
    else if(op == "*")
        return a*b;
    
    return -1;
}