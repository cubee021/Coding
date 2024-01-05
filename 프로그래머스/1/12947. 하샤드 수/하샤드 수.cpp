#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int sum = 0;
    int k = x;
    while(k != 0)
    {
        sum += k%10;
        k /= 10;
    }
    
    return x%sum == 0;
}