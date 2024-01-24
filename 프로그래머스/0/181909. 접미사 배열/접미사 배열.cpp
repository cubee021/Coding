#include <string>
#include <vector>
#include <set>
using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    set<string> s;
    
    for(int i=0; i<my_string.length(); i++)
        s.insert(my_string.substr(i, my_string.length()-i));
                 
    answer.assign(s.begin(), s.end());           
    return answer;
}