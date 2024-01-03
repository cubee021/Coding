#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<long long> v;
    while(n != 0)
    {
        long long k = n%10;
        n = n/10;
        v.push_back(k);
    }
    sort(v.begin(), v.end(), greater<long long>());
    
    for(auto& i : v)
    {
        answer += i;
        answer *= 10;
    }
    answer /= 10;
    
    return answer;
}