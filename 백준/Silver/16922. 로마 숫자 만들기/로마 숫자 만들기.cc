#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
int answer = 0;
int check[1001];

vector<int> num = { 1, 5, 10, 50 };

void DFS(int start = 0, int sum = 0)
{
    if (N == 0)
    {
        if (!check[sum])
        {
            answer++;
            check[sum] = true;
        }
        return;
    }

    for (int i = start; i < 4; i++)
    {
        N--;
        DFS(i, sum + num[i]);
        N++;
    }

}

int main()
{
    cin >> N;
    memset(check, 0, sizeof(check));

    DFS();

    cout << answer;
}