#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> B(N, 0);
    for (int i = 0; i < N; i++)
        cin >> B[i];

    int answer = 0;
    while (true)
    {
        int zero = 0;

        for (int& b : B)
        {
            if (b % 2)
                answer++, b--;

            if (b == 0)
                zero++;
        }

        if (zero == N) break;

        for (int& b : B)
            b /= 2;

        answer++;
    }

    cout << answer;
}