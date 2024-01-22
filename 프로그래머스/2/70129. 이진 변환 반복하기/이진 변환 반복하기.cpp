#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2, 0); // turn, total_zero
    
    while(s != "1")
    {
        int count = 0;
        for(char c : s)
            c == '1' ? count++ : answer[1]++;
        
        s = "";
        while(count != 0)
        {
            s += to_string(count%2);
            count /= 2;
        }
        
        reverse(s.begin(), s.end());
        
        answer[0]++;
    }
    
    return answer;
}