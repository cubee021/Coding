#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
    int r= a%b;
    
    while(r > 0)
    {
        a = b;
        b = r;
        r = a%b;
    }
    
    return b;
}

int lcm(int a, int b)
{
    return a*b / gcd(a, b);
}

int solution(vector<int> arr) {
    int answer = 0;
    
    if(arr.size() == 1) return arr[0];
    
    sort(arr.begin(), arr.end());
    answer = lcm(arr[0], arr[1]);
    
    for(int i=2; i<arr.size(); i++)
        answer = lcm(answer, arr[i]);
    
    return answer;
}