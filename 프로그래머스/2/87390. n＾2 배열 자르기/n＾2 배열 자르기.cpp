#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    pair<long long, long long> begin_idx = {left/n, left%n};
    pair<long long, long long> end_idx = {right/n, right%n};
    
    for(long long xpos=begin_idx.first; xpos<=end_idx.first; xpos++)
    {
        long long number = xpos+1;
        
        for(long long ypos=0; ypos<n; ypos++)
        {
            if(number <= ypos) number++;
            
            if(begin_idx.first == end_idx.first)
            {
                if(ypos >= begin_idx.second && ypos<=end_idx.second)
                    answer.push_back(number);
            }
            else if(xpos == begin_idx.first)
            {
                if(ypos >= begin_idx.second && ypos<n)
                    answer.push_back(number);
            }
            else if(xpos == end_idx.first)
            {
                if(ypos >= 0 && ypos<=end_idx.second)
                    answer.push_back(number);
            }
            else
            {
                answer.push_back(number);
            }
            
        }
    }
    
    return answer;
}