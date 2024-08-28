#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N, answer = 0;
long long L, R, X;

bool check[16];

void backTracking(vector<int>& A, int start, int cur, int sum)
{
    if (sum > R) return;

    if (sum >= L && sum <= R)
        if (A[cur] - A[start] >= X) answer++;

    for (int i = cur + 1; i < N; i++)
    {
        if (check[i]) continue;

        check[i] = true;
        backTracking(A, start, i, sum + A[i]);
        check[i] = false;
    }
}

int main()
{
    cin >> N >> L >> R >> X;

    memset(check, false, sizeof(check));

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
    {
        check[i] = true;

        backTracking(A, i, i, A[i]);

        check[i] = false;
    }

    cout << answer;
}