#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    
    vector<int> v;
    long long sum1 = 0, sum2 = 0;
    for(int e : queue1)
    {
        v.push_back(e);
        sum1 += e;
    }
    
    for(int e : queue2)
    {
        v.push_back(e);
        sum2 += e;
    }
    
    int p1 = 0;
    int p2 = v.size() / 2;
    
    int cnt = 0;
    while(cnt < v.size()*2)
    {
        if(sum1 == sum2)
        {
            if(answer == -1 || answer > cnt) answer = cnt;
            break;
        }
        else if(sum1 > sum2)
        {
            sum1 -= v[p1];
            sum2 += v[p1];
            
            p1 = p1+1 >= v.size() ? 0 : p1+1;
        }
        else
        {
            sum1 += v[p2];
            sum2 -= v[p2];
            
            p2 = p2+1 >= v.size() ? 0 : p2+1;
        }
        
        cnt++;    
    }
    
    return answer;
}