#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    char x = s[0];
        
    int x_cnt = 0;
    int others_cnt = 0;
    
    for(int i=0; i<s.length(); i++)
    {
        x == s[i] ? x_cnt++ : others_cnt++;
        
        if(x_cnt == others_cnt)
        {
            x = s[i+1];
            answer++;
            x_cnt = 0;
            others_cnt = 0;
        }
    }
    
    if(x_cnt != others_cnt)
        answer++;
    
    return answer;
}