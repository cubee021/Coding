#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int M, N;
    cin >> M >> N;

    vector<bool> isPow(N+1, false);
    for (int i = 1; i * i <= N; i++)
        isPow[i * i] = true;

    int sum = 0;
    int min_ = -1;
    for (int i = M; i <= N; i++)
    {
        if (isPow[i])
        {
            if (min_ == -1) min_ = i;
            sum += i;
        }
    }

    if (sum == 0)
    {
        cout << -1;
        return 0;
    }

    cout << sum << '\n' << min_;
}