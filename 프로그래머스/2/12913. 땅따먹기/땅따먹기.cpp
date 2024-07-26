#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int n = land.size();

    for(int i=1; i<n; i++)
    {
        for(int j=0; j<4; j++)
        {
            int temp = land[i][j];
            for(int k=0; k<4; k++)
            {
                if(j == k) continue;
                
                land[i][j] = max(land[i][j], temp + land[i-1][k]);
            }
        }
    }

    answer = *max_element(land[n-1].begin(), land[n-1].end());
    return answer;
}