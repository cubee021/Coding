#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    if(s.length() % 2 == 0)
        return s.substr(s.length()/2-1, 2);
    else
        return s.substr(s.length()/2, 1);
    
}