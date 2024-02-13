#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int comp(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

int solution(vector<int> array) {
    map<int, int> m;
    vector<pair<int, int>> temp;
    
    for(int i : array)
        m.find(i) != m.end() ? m[i]++ : m[i] = 1;
    
    temp.assign(m.begin(), m.end());
    sort(temp.begin(), temp.end(), comp);
    
    return temp[0].second == temp[1].second ? -1 : temp[0].first;
}