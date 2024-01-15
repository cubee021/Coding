#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> set;
    for(int i=0; i<numbers.size(); i++)
        for(int j=i+1; j<numbers.size(); j++)
            set.insert(numbers[i]+numbers[j]);
    
    answer.assign(set.begin(), set.end());
    
    return answer;
}