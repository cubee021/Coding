#include <string>
#include <vector>
#include <queue>
using namespace std;

bool next_similar(string& s1, string& s2)
{
    int cnt = 0;
    for (int i = 0; i < s1.length(); i++)
        if (s1[i] == s2[i]) cnt++;

    if (cnt == s1.length() - 1)
        return true;

    return false;
}

int solution(string begin, string target, vector<string> words) {
    int n = words.size();
    vector<bool> check(n, false);
    
    queue<pair<string, int>> q;
    q.push({begin, 0});
    
    while (!q.empty())
    {
        string s = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (s == target)
            return cnt;

        if (cnt > n)
            continue;

        for (int i = 0; i < n; i++)
        {
            string word = words[i];

            if (next_similar(s, word) && !check[i])
            {
                q.push({ word, cnt + 1 });
                check[i] = true;
            }
        }
    }
    
    return 0;
}