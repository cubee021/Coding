#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(char c : s)
    {
        if(isalpha(c))
        {
            int i=0;
            for(int i=0; i<n; i++)
            {
                c++;
                if(c == 'z'+1)
                    c = 'a';
                else if(c == 'Z'+1)
                    c = 'A';
            }
        }
        
        answer += c;
    }
    return answer;
}