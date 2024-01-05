#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int cnt = 0;
    long temp = num;
    
    while(temp != 1)
    {   
        temp = temp%2 == 0 ? temp/2 : temp*3+1;
        
        if(cnt++ == 500)
            return -1;
    }
    
    return cnt;
}