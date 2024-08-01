#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end());
    
    int prev = routes[0][1];
    for(int i=1; i<routes.size(); i++)
    {
        if(prev < routes[i][0])
        {
            answer++;
            prev = routes[i][1];
        }
        
        if(prev >= routes[i][1])
            prev = routes[i][1];
    }
    
    return answer + 1;
}