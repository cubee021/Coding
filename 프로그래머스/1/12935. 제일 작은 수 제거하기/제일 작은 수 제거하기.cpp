#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int min = 0;
    for(int i=0; i<arr.size(); i++)
        if(arr[min] > arr[i])
            min = i;
    
    for(int i=0; i<arr.size(); i++)
        if(i != min)
            answer.push_back(arr[i]);
    
    if(answer.empty())
        answer.push_back(-1);
    
    return answer;
}