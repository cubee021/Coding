#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int comp(vector<int> a, vector<int> b)
{
    return a[1] < b[1];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    
    for(auto job : jobs)
        pq.push(job);
    
    int time = 0;
    while(!pq.empty())
    {
        vector<vector<int>> next;
        
        while(!pq.empty())
        {
            if(pq.top()[0] > time) break;
            
            next.push_back(pq.top());
            pq.pop();
        }
        
        if(next.empty())
        {
            time++;
            continue;
        }
        
        sort(next.begin(), next.end(), comp);
        
        for(int i=0; i<next.size(); i++)
        {
            if(i == 0)
            {
                answer += (time - next[i][0]) + next[i][1];
                time += next[i][1];
            }
            else
            {
                pq.push(next[i]);
            }
        }
    }
    
    return answer / jobs.size();
}