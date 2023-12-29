#include <string>
#include <vector>

using namespace std;

vector<string> solution(string myStr) {
    vector<string> answer;
    string s = "";
    
    for(char c : myStr)
    {
        if(c=='a' || c=='b' || c=='c')
        {
            if(s.length() != 0)
            {
                answer.push_back(s);
                s = "";
            }
        }
        else
            s += c;
    }
    
    if(s.length() != 0)
        answer.push_back(s);
    
    if(answer.empty())
        answer.push_back("EMPTY");
    
    return answer;
}