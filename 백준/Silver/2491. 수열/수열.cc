#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int answer = 1;
    int asc = 1;
    int desc = 1;

    for (int i = 0; i < N-1; i++)
    {
        if (arr[i] <= arr[i + 1]) asc++;
        else asc = 1;

        if (arr[i] >= arr[i + 1]) desc++;
        else desc = 1;

        answer = max(answer, max(asc, desc));
    }

    cout << answer;
}