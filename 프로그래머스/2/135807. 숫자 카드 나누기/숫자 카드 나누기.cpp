#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
    int r;
    while(b != 0)
    {
        r = a%b;
        a = b;
        b = r;
    }
    
    return a;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    bool ok1 = true;
    int r1 = arrayA[0];
    for(int i=1; i<arrayA.size(); i++)
        r1 = gcd(r1, arrayA[i]);
    
    for(int i : arrayB)
        if(i % r1 == 0)
        {
            ok1 = false;
            break;
        }
    
    bool ok2 = true;
    int r2 = arrayB[0];
    for(int i=1; i<arrayB.size(); i++)
        r2 = gcd(r2, arrayB[i]);
    
    for(int i : arrayA)
        if(i % r2 == 0)
        {
            ok2 = false;
            break;
        }
    
    if(ok1 && !ok2) return r1;
    else if(!ok1 && ok2) return r2;
    else if(ok1 && ok2) return max(r1, r2);
    else return 0;
}