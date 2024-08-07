#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int arr[2001];
int DP[2001][2001];

int is_palindrom(int i, int j)
{
    if (i == j) return 1;
    else if (i + 1 == j)
    {
        if (arr[i] == arr[j]) return 1;
        else return 0;
    }

    if (DP[i][j] >= 0) return DP[i][j];

    if (arr[i] != arr[j]) return DP[i][j] = 0;
    else return DP[i][j] = is_palindrom(i + 1, j - 1);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    cin >> M;

    memset(DP, -1, sizeof(DP));
    for (int i = 0; i < M; i++)
    {
        int S, E;
        cin >> S >> E;

        cout << is_palindrom(--S, --E) <<'\n';
    }
}