#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int solution(int n) {
    int answer = 0;
    string s = "";
    
    while(n>0)
    {
        s += n%3;
        n /= 3;
    }
    reverse(s.begin(), s.end());
    
    for(int i=0; i<s.length(); i++)
    {
        answer += pow(3, i) * s[i];
    }
    return answer;
}