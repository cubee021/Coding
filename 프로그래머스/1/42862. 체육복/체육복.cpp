#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    map<int, int> m;
    
    for(int i=0; i<n; i++) m[i+1] = 1;
    
    for(int l : lost) m[l]--;
    
    for(int r : reserve) m[r]++;
    
    for(int i=1; i<=n; i++)
    {
        if(m[i] == 0)
            if(m[i-1] == 2)
            {
                m[i]++;
                m[i-1]--;
            }
            else if(m[i+1] == 2)
            {
                m[i]++;
                m[i+1]--;
            }
    }
    
    for(auto& i : m)
        if(i.second > 0)
            answer++;
    
    
    return answer;
}