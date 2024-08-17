#include <iostream>
#include <vector>
using namespace std;
#define max_ 1001

int main()
{
    int n;
    cin>>n;
    
    vector<int> num(n);
    for(int i=0; i<n; i++)
        cin>>num[i];
    
    vector<int> isPrime(max_, true);
    isPrime[0] = false;
    isPrime[1] = false;
    
    for(int i=2; i<=max_; i++)
        if(isPrime[i])
            for(int j=i*i; j<=max_; j+=i)
                isPrime[j] = false;
    
    int answer = 0;
    for(int i : num)
        if(isPrime[i]) answer++;
    
    cout<<answer;
    
}