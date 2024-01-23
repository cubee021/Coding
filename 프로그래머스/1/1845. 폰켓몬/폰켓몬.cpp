#include <vector>
using namespace std;

int solution(vector<int> nums)
{
    vector<int> temp{nums[0]};
    int answer = 0;
    
    for(int i=1; i<nums.size(); i++)
    {
        int j;
        for(j=0; j<temp.size(); j++)
        {
            if(temp[j] == nums[i])
                break;
        }
        if(j == temp.size())
            temp.push_back(nums[i]);
        
    }
        
    answer = temp.size() > nums.size()/2 ? nums.size()/2 : temp.size();
    
    return answer;
}