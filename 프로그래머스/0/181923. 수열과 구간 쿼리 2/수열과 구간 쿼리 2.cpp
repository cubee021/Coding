#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    
    for(auto query : queries)
    {
        vector<int> temp(arr.begin()+query[0], arr.begin()+query[1]+1);
        sort(temp.begin(), temp.end());
        
        int i;
        for(i=0; i<temp.size(); i++)
        {
            if(query[2] < temp[i])
            {
                answer.push_back(temp[i]);
                break;
            }
        }
        if(i == temp.size())
            answer.push_back(-1);
    }
    
    return answer;
}