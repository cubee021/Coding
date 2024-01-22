#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    vector<string> parts{"aya", "ye", "woo", "ma"};
    int answer = 0;
    
    for(string b : babbling)
    {
        for(string p : parts)
        {
            if(b.find(p) != string::npos)
                b.replace(b.find(p), p.length(), "0");
        }
        
        int i;
        for(i=0; i<b.length(); i++)
        {
            if(isalpha(b[i]))
                break;
        }
        
        if(i == b.length())
            answer++;
    }
    return answer;
}