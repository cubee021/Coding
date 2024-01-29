#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    stack<int> finished;
    
    int idx = 1;
    while(true)
    {
        for(int i=0; i<speeds.size(); i++)
            progresses[i] += speeds[i];
        
        int temp = 0;
        for(int i=idx; i<=speeds.size(); i++)
        {
            if(progresses[i-1] >= 100 && i == idx)
            {
                temp++;
                idx++;
            }
        }
        if(temp != 0)
            answer.push_back(temp);
        
        int sum = 0;
        for(int a : answer)
            sum += a;
        
        if(sum == speeds.size())
            break;
    }
    
    return answer;
}