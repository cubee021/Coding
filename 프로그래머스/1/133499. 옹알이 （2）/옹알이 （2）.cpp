#include <string>
#include <vector>
using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    for(string s : babbling)
    {
        for(int i=0; i<s.length(); i++)
        {
            if(s.substr(i, 3) == "aya") s.replace(i, 3, "!");
            else if(s.substr(i, 2) == "ye") s.replace(i, 2, "#");
            else if(s.substr(i, 3) == "woo") s.replace(i, 3, "$");
            else if(s.substr(i, 2) == "ma") s.replace(i, 2, "*");
        }
        
        int i;
        char before = '0';
        for(i=0; i<s.length(); i++)
        {
            if(isalpha(s[i]) || before==s[i])
                break;
            
            before = s[i];
        }

        if(i == s.length())
            answer++;
    }
    
    return answer;
}