#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int solution(vector<int> sticker)
{
    int answer =0;
    int N = sticker.size();
    
    if(N == 1) return sticker[0];
    else if(N == 2) return max(sticker[0], sticker[1]);
    
    vector<int> DP(N, -1);
    
    DP[0] = sticker[0];
    DP[1] = DP[0];
    
    for(int i=2; i<N-1; i++)
        DP[i] = max(DP[i-1], DP[i-2] + sticker[i]);
    
    answer = DP[N-2];
    DP.assign(DP.size(), -1);
    
    DP[0] = 0;
    DP[1] = sticker[1];
    
    for(int i=2; i<N; i++)
    {
        DP[i] = max(DP[i-1], DP[i-2] + sticker[i]);
    }
    
    answer = max(answer, DP[N-1]);
    
    return answer;
}