#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<int> dp{1, 2};
    
    if(n>1)
    {
        for(int i=2; i<n; i++)
            dp.push_back((dp[i-1] + dp[i-2]) % 1000000007);
    }
    
    return dp[n-1];
}