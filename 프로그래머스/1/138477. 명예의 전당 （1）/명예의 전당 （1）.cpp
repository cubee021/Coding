#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> temp;
    for(int i : score)
    {
        temp.push_back(i);
        sort(temp.begin(), temp.end(), greater<int>());
        
        answer.push_back(temp.size()<=k ? temp[temp.size()-1] : temp[k-1]);
    }
    
    return answer;
}