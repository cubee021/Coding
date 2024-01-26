#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(string my_string, string is_suffix) {
    set<string> s;
    for(int i=0; i<my_string.length(); i++)
        s.insert(my_string.substr(i, my_string.length()-i));
    
    if(s.find(is_suffix) != s.end())
        return 1;
    
    return 0;
    
}