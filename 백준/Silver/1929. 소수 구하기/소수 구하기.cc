#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;
    
    vector<long long> isPrime(m+1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for(long long i=2; i<=m; i++)
        if(isPrime[i])
            for(long long j=i*i; j<=m; j+=i)
                isPrime[j] = false;
    
    for(long long i=n; i<=m; i++)
        if(isPrime[i]) cout<<i<<'\n';
    
}