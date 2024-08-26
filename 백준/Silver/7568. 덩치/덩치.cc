#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<pair<int, int>> info(N); // weight, height
    for (auto& i : info)
        cin >> i.first >> i.second;

    for (int i = 0; i < N; i++)
    {
        int w = info[i].first;
        int h = info[i].second;

        int cnt = 1;
        for (auto i : info)
        {
            if (w < i.first && h < i.second)
                cnt++;
        }

        cout << cnt << ' ';
    }

}