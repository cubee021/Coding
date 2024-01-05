#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int cnt = 0;
    for(char c : s)
    {   
        if(c == ' ')
        {
            answer += c;
            cnt = 0;
        }
        else
        {
            answer += cnt%2==0 ? toupper(c) : tolower(c);
            cnt++;
        }
    }
    return answer;
}