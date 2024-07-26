#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    vector<bool> must(91, false);
    queue<char> q;

    for (char c : skill)
    {
        must[c] = true;
        q.push(c);
    }

    for (string tree : skill_trees)
    {
        queue<char> temp = q;
        bool ok = true;

        for (char c : tree)
        {
            if (temp.empty()) break;

            if (must[c] && temp.front() == c)
                temp.pop();
            else if (must[c] && temp.front() != c)
            {
                ok = false;
                break;
            }
        }

        if (ok) answer++;
    }

    return answer;
}