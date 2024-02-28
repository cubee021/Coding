#include <string>
#include <vector>
#include <set>
using namespace std;

long long solution(int n) {
    vector<long long> dp = {1, 2};
    
    if(n > 2)
        for(int i=2; i<n; i++)
            dp.push_back((dp[i-2] + dp[i-1])%1234567);
    
    return dp[n-1];
}