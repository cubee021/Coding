#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> v;
    
    for(string op : operations)
    {
        char c = op[0];
        int num = stoi(op.substr(2, op.length()-2));
        
        if(c == 'I') v.push_back(num);
        else if(c == 'D' && !v.empty())
        {
            if(num == 1) // max
            {
                sort(v.begin(), v.end());
                v.pop_back();
            }
            else // min
            {
                sort(v.begin(), v.end(), greater<>());
                v.pop_back();
            }
        }
    }
    
    sort(v.begin(), v.end());
    
    if(v.empty()) return {0, 0};
    else return {v[v.size()-1], v[0]};
}