#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

int N, M;
int R[1001]; // 세로합
int C[1001]; // 가로합

int main()
{
    cin >> N >> M;

    int sum = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            int a;
            cin >> a;

            if (i == 0 || i == N - 1 || j == 0 || j == M - 1)
            {
                if ((i == 0 && j == 0) || (i == 0 && j == M - 1) || (i == N - 1 && j == 0) || (i == N - 1 && j == M - 1))
                {
                    R[i] += a;
                    C[j] += a;
                    sum += a;
                }
                else
                {
                    R[i] += (2 * a);
                    C[j] += (2 * a);
                    sum += (2 * a);
                }
            }
            else
            {
                R[i] += (4 * a);
                C[j] += (4 * a);
                sum += (4 * a);
            }
        }

    int answer = INT_MIN;
    for (int i = 1; i < N - 1; i++)
    {
        answer = max(answer, sum - R[i] / 2 + R[0]);
        answer = max(answer, sum - R[i] / 2 + R[N - 1]);
    }

    for (int i = 1; i < M - 1; i++)
    {
        answer = max(answer, sum - C[i] / 2 + C[0]);
        answer = max(answer, sum - C[i] / 2 + C[M - 1]);
    }

    answer = max(answer, sum);

    cout << answer;
}