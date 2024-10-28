#include <string>
#include <vector>

using namespace std;

vector<int> answer;

long long factorial(int n)
{
    if(n == 0) return 1;
    
    return n * factorial(n-1);
}

void permutation(vector<int>& v, long long& k)
{
    if(v.size() == 1)
    {
        answer.push_back(v[0]);
        return;
    }
    
    long long f = factorial(v.size()-1);
    for(int i=1; i<=v.size(); i++)
    {
        if(i*f >= k)
        {
            answer.push_back(v[i-1]);
            v.erase(v.begin()+i-1);
            
            k -= (i-1) * f;
            permutation(v, k);
        }
    }
}

vector<int> solution(int n, long long k) {
    vector<int> v;
    for(int i=1; i<=n; i++)
        v.push_back(i);
    
    permutation(v, k);
    
    return answer;
}