#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void get_prime(vector<long>& prime, long N)
{
	vector<bool> IsPrime(N + 1, true);

	for (long i = 2; i <= N; i++)
	{
		if (IsPrime[i])
		{
			prime.push_back(i);

			for (long j = i * i; j <= N; j += i)
				IsPrime[j] = false;
		}
	}
}

int main()
{
	long N, answer = 0;
	cin >> N;

	vector<long> prime;
	get_prime(prime, N);
	prime.push_back(-1);

	long l = 0, r = 0, sum = prime[l];
	while (l <= r && r < prime.size()-1)
	{
		if (sum == N)
		{
			answer++;

			sum += prime[++r];
		}
		else if (sum > N) sum -= prime[l++];
		else sum += prime[++r];

	}

	if (r == prime.size()) answer = 0;
	cout << answer;
}