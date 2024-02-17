#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int comp(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    map<int, int> m;
    vector<pair<int, int>> temp;
    string number = "";
    
    for(char c : s)
    {
        if(isdigit(c))
            number += c;
        else if(c == ',' || c == '}')
            if(number.length() != 0)
            {
                int n = stoi(number);
                m.find(n) != m.end() ? m[n]++ : m[n] = 1;
                
                number = "";
            }
    }
    
    temp.assign(m.begin(), m.end());
    sort(temp.begin(), temp.end(), comp);
    
    for(auto t : temp)
        answer.push_back(t.first);
    
    return answer;
}