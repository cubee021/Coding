#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(vector<int> sides) {
    int answer = 0;
    int longer = sides[0] > sides[1] ? sides[0] : sides[1];
    int shorter = sides[0] > sides[1] ? sides[1] : sides[0];
    
    //가장 긴 변 : longer
    for(int i=longer-shorter+1; i<=longer; i++)
        answer++;
    
    //가장 긴 변 : a
    for(int i=longer+1; i<longer+shorter; i++)
        answer++;
    
    return answer;
}