#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_prefix) {
    int answer = 0;
    if(my_string.find(is_prefix) != string::npos)
    {
        if(my_string.find(is_prefix) == 0)
            return 1;
    }
    
    return 0;
}