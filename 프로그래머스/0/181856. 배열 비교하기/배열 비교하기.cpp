#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr1, vector<int> arr2) {
    if(arr1.size() > arr2.size()) return 1;
    else if(arr1.size() < arr2.size()) return -1;
    else
    {
        int sum1 = 0;
        int sum2 = 0;
        for(int i=0; i<arr1.size(); i++)
        {
            sum1 += arr1[i];
            sum2 += arr2[i];
        }
        
        if(sum1 > sum2) return 1;
        else if(sum1 < sum2) return -1;
        else return 0;
    }
    
    return -2;
}