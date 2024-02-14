#include <string>
#include <vector>
#include <deque>
#include <set>
using namespace std;

int solution(vector<int> elements) {
    set<int> answers;
    deque<int> dq(elements.begin(), elements.end());
    
    for(int i=1; i<=elements.size(); i++) // 추출할 길이
    {
        int sum = 0;
        
        for(int j=0; j<elements.size(); j++)
        {
            for(int k=0; k<i; k++)
            {
                sum += dq.front();
                dq.push_back(dq.front());
                dq.pop_front();
            }
            
            answers.insert(sum);
            sum = 0;
            
            for(int k=0; k<i-1; k++)
            {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
        
    }
    
    return answers.size();
}