#include <string>
#include <vector>
using namespace std;

string solution(string s, string skip, int index) {
    string answer = s;
    
    for(char& c : answer)
    {
        for(int i=0; i<index; i++)
        {
            c == 'z' ? c = 'a' : c++;
            
            if(skip.find(c) != string::npos)
                i--;
            
        }
    }
    
    return answer;
}