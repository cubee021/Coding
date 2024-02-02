#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s, string skip, int index) {
    string answer = s;
    
    for(char& c : answer)
    {
        for(int i=0; i<index; i++)
        {
            c == 'z' ? c = 'a' : c++;
            
            if(find(skip.begin(), skip.end(), c) != skip.end())
                i--;
            
        }
    }
    
    return answer;
}