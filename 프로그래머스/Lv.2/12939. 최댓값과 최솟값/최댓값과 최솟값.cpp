#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    string temp = "";
    vector<int> v;
    
    for(char c : s)
    {
        if(isdigit(c) || c == '-')
            temp += c;
        else
        {
            v.push_back(stoi(temp));
            temp = "";
        }
    }
    v.push_back(stoi(temp));
    
    sort(v.begin(), v.end());
    answer = to_string(v[0]) + ' ' + to_string(v[v.size()-1]);
    
    return answer;
}