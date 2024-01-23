#include <string>
#include <vector>
using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string> parts{"aya", "ye", "woo", "ma"};
    vector<string> symbols{"!", "#", "$", "*"};
    
    for(string s : babbling)
    {
        //여러번 나와서 점검하도록 수정
        for(int i=0; i<parts.size(); i++)
            if(s.find(parts[i]) != string::npos)
                s.replace(s.find(parts[i]), parts[i].length(), symbols[i]);

        for(int i=0; i<parts.size(); i++)
            if(s.find(parts[i]) != string::npos)
                s.replace(s.find(parts[i]), parts[i].length(), symbols[i]);
        
        for(int i=0; i<parts.size(); i++)
            if(s.find(parts[i]) != string::npos)
                s.replace(s.find(parts[i]), parts[i].length(), symbols[i]);
        
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