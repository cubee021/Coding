#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> turn(N + 1, -1);
    turn[1] = 0; // 0 == SK, 1 == CY

    for (int i = 2; i < N; i++)
    {
        if (turn[i - 1] == 0) turn[i] = 1;
        else turn[i] = 0;
    }

    turn[N - 2] ? cout << "CY" : cout << "SK";
}