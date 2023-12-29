#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    string word = "";
    for(char c : my_string)
    {
        if(c == ' ')
        {
            if(word.length() != 0)
            {
                answer.push_back(word);
                word = "";
            }
        }
        else
            word += c;
    }
    
    if(word.length() != 0)
        answer.push_back(word);
    
    return answer;
}