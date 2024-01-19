#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int temp1 = 0;
    int temp2 = 1;
    for(int i=2; i<=n; i++)
    {
        answer = temp1 + temp2;
        i%2 == 0 ? temp1=answer%1234567 : temp2=answer%1234567;
    }
    
    return answer%1234567;
}