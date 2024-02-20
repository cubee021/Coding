#include <string>
#include <vector>

using namespace std;

void recursion(vector<int>& numbers, int& answer, int target, int idx=0, int sum=0)
{
    if(idx == numbers.size())
    {
        if(sum == target) answer++;
        return;
    }
    
    recursion(numbers, answer, target, idx+1, sum+numbers[idx]);
    recursion(numbers, answer, target, idx+1, sum-numbers[idx]);
}


int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    recursion(numbers, answer, target);
    
    return answer;
}