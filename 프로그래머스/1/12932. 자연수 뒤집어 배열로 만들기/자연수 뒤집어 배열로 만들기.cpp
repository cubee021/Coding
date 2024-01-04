#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    
    string s = to_string(n);
    int i=s.length()-1;
    while(i >= 0)
    {
        answer.push_back(s[i] - '0');
        i--;
    }
    return answer;
}