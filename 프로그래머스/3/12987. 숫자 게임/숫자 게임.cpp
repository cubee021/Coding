#include <string>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    sort(A.begin(), A.end(), greater<>());
    sort(B.begin(), B.end(), greater<>());
    
    deque<int> dq = {B.begin(), B.end()};
    
    for(int a : A)
    {
        if(a < dq.front())
        {
            answer++;
            dq.pop_front();
        }
        else
        {
            dq.pop_back();
        }
    }
    
    return answer;
}