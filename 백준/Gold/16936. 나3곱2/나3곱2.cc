#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int N;

bool DFS(map<long long, int>& map, vector<long long>& a)
{
    if (a.size() == N)
    {
        for (long long i : a) cout << i << ' ';
        return true;
    }

    long long num = a.back();
    vector<long long> temp = a;

    if (num % 3 == 0 && map.find(num/3) != map.end())
    {
        if (map[num / 3] != 0)
        {
            temp.push_back(num / 3);
            map[num / 3]--;

            DFS(map, temp);

            temp.pop_back();
            map[num / 3]++;
        }
    }

    if (map.find(num*2) != map.end() && map[num*2] != 0)
    {
        temp.push_back(num * 2);
        map[num * 2]--;

        DFS(map, temp);

        map[num * 2]++;
    }

    return false;
}

int main()
{
    cin >> N;

    vector<long long> start(N);
    map<long long, int> map; // num, cnt
    for (int i = 0; i < N; i++)
    {
        long long n;
        cin >> n;

        start[i] = n;
        map[n]++;
    }

    for (long long s : start)
    {
        vector<long long> answer;
        answer.push_back(s);

        if (DFS(map, answer)) break;
    }

}