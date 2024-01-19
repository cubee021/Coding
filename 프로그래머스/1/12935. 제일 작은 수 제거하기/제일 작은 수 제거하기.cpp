#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer = arr;
    
    int min = *min_element(answer.begin(), answer.end());
    int idx = find(answer.begin(), answer.end(), min) - answer.begin();
    answer.erase(answer.begin() + idx);
    
    return answer.empty() ? vector<int>(1, -1) : answer;
}