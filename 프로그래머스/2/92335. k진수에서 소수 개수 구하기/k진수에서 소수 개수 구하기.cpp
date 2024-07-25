#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool is_prime(long long ll) {
    if(ll < 2) return false;
        
    for(long long i=2; i*i<=ll; ++i) {
        if(ll % i == 0) return false;
    }
    
    return true;
}

int solution(int n, int k) {
    int answer = 0;

    string s = "";
    while (n > 0)
    {
        s += (n % k + '0');
        n /= k;
    }

    reverse(s.begin(), s.end());
    string temp = "";

    for (char c : s)
    {
        if (c != '0') temp += c;
        else
        {
            if (temp != "" && is_prime(stoll(temp)))
                answer++;

            temp = "";
        }
    }
    if (temp != "" && is_prime(stoll(temp)))
        answer++;
    
    return answer;
}