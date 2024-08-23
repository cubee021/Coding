#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int N;
    cin >> N;

    long long answer = 666;
    while (N-1 > 0)
    {
        answer++;
        
        string s = to_string(answer);
        if(s.find("666") != string::npos)
            N--;
    }

    cout << answer;
}