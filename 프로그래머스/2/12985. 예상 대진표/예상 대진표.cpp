#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int turn = 1;
    a -= 1, b -= 1;
    
    while(turn < n)
    {   
        if(a < b)
        {
            if(a+1 == b && a%2 == 0 && b%2 == 1)
                return turn;
        }
        else
        {
            if(a == b+1 && b%2 == 0 && a%2 == 1)
                return turn;
        }
        
        turn++;
        a /= 2, b /= 2;
    }
    
    return -1;
}