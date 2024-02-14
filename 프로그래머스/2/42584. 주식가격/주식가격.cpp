#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;

    for(int i=0; i<prices.size(); i++)
    {
        int temp = 0;
        int j;
        for(j=i+1; j<prices.size(); j++)
        {
            temp++;
            
            if(prices[i] > prices[j])
            {
                answer.push_back(temp);
                break;
            }
        }
        
        if(j == prices.size())
            answer.push_back(temp);
    }
                
    return answer;
}