#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    vector<int> v;
    string num = "";
    
    for(int i=0; i<s.length(); i++)
    {
        if(isalpha(s[i]))
            v.pop_back();
        else if(s[i] == ' ' && num.length() != 0)
        {
            v.push_back(stoi(num));
            num = "";
        }
        else
            num += s[i];
    }
    if(num.length() != 0)
        v.push_back(stoi(num));
    
    for(int i : v)
        answer += i;
    
    return answer;
}