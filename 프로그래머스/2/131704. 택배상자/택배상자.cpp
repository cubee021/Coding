#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    int n = order.size();

    int cur = 1;
    stack<int> sub;

    for (int o : order)
    {
        if (cur == o)
        {
            answer++, cur++;
        }
        else
        {
            if (!sub.empty() && sub.top() == o)
            {
                answer++;
                sub.pop();

                continue;
            }

            if (cur > n) break;

            while (cur != o && cur <= n)
                sub.push(cur++);
            
            if (cur == o) answer++;

            cur++;
        }
    }

    return answer;
}