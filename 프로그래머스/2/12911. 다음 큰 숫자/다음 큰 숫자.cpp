#include <string>
#include <vector>

using namespace std;

int count_one(int n)
{
    int result = 0;
    while(n > 0)
    {
        if(n%2 == 1) result++;
        n /= 2;
    }
    
    return result;
}

int solution(int n) {
    int cnt = count_one(n);
    n++;
    
    while(cnt != count_one(n))
    {
        n++;
    }
    
    return n;
}