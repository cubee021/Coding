#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(string my_string, string is_suffix) {
    
    for(int i=0; i<my_string.length(); i++)
    {
        string temp = my_string.substr(i);
        
        if(temp == is_suffix)
            return 1;
    }
    
    return 0;
    
}