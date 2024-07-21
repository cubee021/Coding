#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

#define N 10000000

int solution(string numbers) {
    int answer = 0;
    vector<int> isPrime(N + 1, true);

    for (int i = 2; i <= N; i++)
        if (isPrime[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                isPrime[j] = false;
            }
        }

    unordered_set<int> set;
    int k = numbers.size();

    vector<int> order;
    for (int j = 0; j < k; j++)
        order.push_back(j);

    do {

        for (int i = 1; i <= k; i++)
        {
            string s = "";
            for (auto j : order)
                s += numbers[j];

            int num = stoi(s.substr(0, i));

            if (num != 0 && num != 1)
                set.insert(num);
        }

    } while (next_permutation(order.begin(), order.end()));

    for (int i : set)
        if (isPrime[i]) answer++;

    return answer;
    
}