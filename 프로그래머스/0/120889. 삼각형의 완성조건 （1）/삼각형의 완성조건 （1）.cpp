#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> sides) {
    sort(sides.begin(), sides.end(), greater<int>());
    
    if(sides[0] < sides[1]+sides[2])
        return 1;
    
    return 2;
}