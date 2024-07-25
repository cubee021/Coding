#include <string>
#include <vector>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<long long> pq(works.begin(), works.end());
    
    while(n > 0)
    {
        if(pq.empty()) break;
        
        long long temp = pq.top() - 1;
        pq.pop();
        
        if(temp > 0)
            pq.push(temp);
        
        n--;
    }
    
    while(!pq.empty())
    {
        answer += pq.top() * pq.top();
        pq.pop();
    }
    
    return answer;
}