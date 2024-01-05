#include <string>
#include <vector>
using namespace std;

int solution(string s) {
    string answer = "";
    string temp = "";
    
    for(char c : s)
    {
        if(isalpha(c))
        {
            temp += c;
            
            if(temp == "zero")
            {
                answer += '0';
                temp = "";
            }
            else if(temp == "one")
            {
                answer += '1';
                temp = "";
            }
            else if(temp == "two")
            {
                answer += '2';
                temp = "";
            }
            else if(temp == "three")
            {
                answer += '3';
                temp = "";
            }
            else if(temp == "four")
            {
                answer += '4';
                temp = "";
            }
            else if(temp == "five")
            {
                answer += '5';
                temp = "";
            }
            else if(temp == "six")
            {
                answer += '6';
                temp = "";
            }
            else if(temp == "seven")
            {
                answer += '7';
                temp = "";
            }
            else if(temp == "eight")
            {
                answer += '8';
                temp = "";
            }
            else if(temp == "nine")
            {
                answer += '9';
                temp = "";
            }
        }
        else
            answer += c;
            
    }
    
    return stoi(answer);
}