#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(auto& c : commands)
    {
        vector<int> temp = array;
        sort(temp.begin()+c[0]-1, temp.begin()+c[1]);
        answer.push_back(temp[c[0]+c[2]-2]);
    }
    
    return answer;
}