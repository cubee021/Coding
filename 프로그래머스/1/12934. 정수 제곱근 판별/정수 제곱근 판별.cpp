#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    double sr = sqrt(n);
    if(sr - floor(sr) == 0)
        answer = (sr+1)*(sr+1);
    else
        answer = -1;
    
    return answer;
}