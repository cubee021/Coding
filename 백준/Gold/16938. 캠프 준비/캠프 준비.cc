#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, answer = 0;
long long L, R, X;

void backTracking(vector<int>& A, int start, int cur, int sum)
{
    if (sum > R) return;

    if (sum >= L && sum <= R)
        if (A[cur] - A[start] >= X) answer++;

    for (int i = cur + 1; i < N; i++)
    {
        backTracking(A, start, i, sum + A[i]);
    }
}

int main()
{
    cin >> N >> L >> R >> X;

    vector<int> A(N, 0);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    sort(A.begin(), A.end());

    if (N == 1)
    {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < N; i++)
        backTracking(A, i, i, A[i]);

    cout << answer;
}