#include <string>
#include <vector>

using namespace std;

void set_answer(vector<int>& answer, int l, int r)
{
    if (answer[0] == -1)
    {
        answer = { l, r };
        return;
    }

    int c1 = abs(answer[0] - answer[1]);
    int c2 = abs(l - r);

    if (c2 < c1)
        answer = { l, r };
}

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer = { -1, -1 };

    int l = 0, r = 0;
    int sum = sequence[0];

    while (l<=r && r < sequence.size())
    {
        if (sum == k)
        {
            set_answer(answer, l, r);

            sum -= sequence[l++];
        }
        else if (sum < k && r < sequence.size() -1)
            sum += sequence[++r];
        else
            sum -= sequence[l++];
    }

    return answer;
}