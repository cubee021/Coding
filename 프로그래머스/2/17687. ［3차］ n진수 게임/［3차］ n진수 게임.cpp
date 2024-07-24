#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(int n, int t, int m, int p) {
    vector<char> alpha = { 'A', 'B', 'C', 'D', 'E', 'F'};
    string answer = "";

    int cnt = 2;
    if (m == p) p = 0;
    if (p == 1) answer += '0';

    for (int i = 1; i <= 1000000; i++)
    {
        string binary = "";
        int num = i;
        while (num > 0)
        {
            int temp = num % n;
            if (temp > 9)
                binary += alpha[temp - 10];
            else
                binary += (temp + '0');

            num /= n;
        }
        
        reverse(binary.begin(), binary.end());
        for (char c : binary)
        {
            if (answer.length() == t) break;
            if (cnt % m == p) answer += c;

            cnt++;
        }
    }

    return answer;
}