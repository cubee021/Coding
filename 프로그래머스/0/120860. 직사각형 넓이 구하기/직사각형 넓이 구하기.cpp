#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<vector<int>> dots) {
    int answer = 0;
    set<int> xpos;
    set<int> ypos;
    
    for(auto dot : dots)
    {
        xpos.insert(dot[0]);
        ypos.insert(dot[1]);
    }
    
    vector<int> v1(xpos.begin(), xpos.end());
    vector<int> v2(ypos.begin(), ypos.end());
    
    int width = v1[1] - v1[0];
    int height = v2[1] - v2[0];
    
    return width * height;
}