#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    
    for(int i=0; i<t.length()-p.length()+1; i++)
    {
        string s = t.substr(i, p.length());

        if(stoll(s) <= stoll(p))
            answer++;
    }  
    
    return answer;
}