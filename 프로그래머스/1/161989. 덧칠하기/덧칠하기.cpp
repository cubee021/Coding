#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    vector<int> v(n, 1);
    for(int i : section)
    {
        v[i-1]--;
    }
    
    while(true)
    {
        if(find(v.begin(), v.end(), 0) != v.end())
        {
            int idx = find(v.begin(), v.end(), 0)-v.begin();
            if(n-idx < m)
            {
                for(int i=n-1; i>n-m; i--)
                    v[i]++;
            }
            else
            {
                for(int i=idx; i<idx+m; i++)
                    v[i]++;
            }
            
            answer++;
        }
        else
            break;
    }
    
    return answer;
}