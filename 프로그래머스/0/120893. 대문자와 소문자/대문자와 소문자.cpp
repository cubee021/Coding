#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    
    int t = 'a' - 'A';
    
    for(char c : my_string)
    {
        if(c < 'a') answer += (c + t);
        else answer += (c-t);
    }
    
    return answer;
}