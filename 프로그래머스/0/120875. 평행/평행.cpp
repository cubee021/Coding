#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> dots) {
    double a1, a2;
    
    //[a-b, c-d]
    a1 = (dots[0][1]-dots[1][1])/(1.0*(dots[0][0]-dots[1][0]));
    a2 = (dots[2][1]-dots[3][1])/(1.0*(dots[2][0]-dots[3][0]));
    if(a1 == a2) return 1;
    
    //[a-c, b-d]
    a1 = (dots[0][1]-dots[2][1])/(1.0*(dots[0][0]-dots[2][0]));
    a2 = (dots[1][1]-dots[3][1])/(1.0*(dots[1][0]-dots[3][0]));
    if(a1 == a2) return 1;
    
    //[a-d, b-c]
    a1 = (dots[0][1]-dots[3][1])/(1.0*(dots[0][0]-dots[3][0]));
    a2 = (dots[1][1]-dots[2][1])/(1.0*(dots[1][0]-dots[2][0]));
    if(a1 == a2) return 1;
    
    return 0;
}