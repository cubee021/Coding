#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string my_string, string letter) {
    string answer = "";
    
    for(char c : my_string)
    {
        string temp = "";
        temp += c;
        
        if(temp != letter)
            answer += c;
    }
    
    return answer;
}