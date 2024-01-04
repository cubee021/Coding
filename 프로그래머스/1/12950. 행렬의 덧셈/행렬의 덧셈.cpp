#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size(), vector<int>(arr1[0].size(), 0));
    
    for(int i=0; i<arr1.size(); i++)
    {
        vector<int> a = arr1[i];
        vector<int> b = arr2[i];
        vector<int>& sum = answer[i];
        for(int j=0; j<a.size(); j++)
        {
            sum[j] = a[j] + b[j];
        }
    }
    return answer;
}