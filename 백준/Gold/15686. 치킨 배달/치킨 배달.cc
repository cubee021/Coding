#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int dist[14][101]; // store num, house num

int main()
{
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> house, store;
    for(int i=0; i<N; i++)
        for (int j = 0; j < N; j++)
        {
            int temp;
            cin >> temp;

            if (temp == 1) house.push_back({ i, j });
            else if (temp == 2) store.push_back({ i, j });
        }

    for (int i=0; i<store.size(); i++)
        for (int j=0; j<house.size(); j++)
        {
            int d = abs(store[i].first - house[j].first) 
                     + abs(store[i].second - house[j].second);

            dist[i][j] = d;
        }

    vector<int> check(store.size(), 1);
    for (int i = 0; i < M; i++)
        check[i] = 0;

    int answer = 5000;
    do {

        vector<int> min_(house.size(), 5000);

        for (int j = 0; j < house.size(); j++)
        {
            for (int i = 0; i < store.size(); i++)
            {
                if (check[i] == 0)
                {
                    min_[j] = min(min_[j], dist[i][j]);
                }
            }
        }

        int sum = 0;
        for (int m : min_) sum += m;

        answer = min(answer, sum);

    } while (next_permutation(check.begin(), check.end()));

    cout << answer;
}