#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> query) {
    
    for(int i=0; i<query.size(); i++)
    {
        if(i%2 == 0)
            arr.assign(arr.begin(), arr.begin()+query[i]+1);
        else
            arr.assign(arr.begin()+query[i], arr.end());
    }
    
    return arr;
}