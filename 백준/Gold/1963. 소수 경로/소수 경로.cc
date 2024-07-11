#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

int change(int password, int& idx, int& num)
{
	if (idx == 0 && num == 0) return -1;

	string s = to_string(password);
	s[idx] = num + '0';

	return stoi(s);
}

int main()
{
	vector<bool> is_prime(10001, true);

	for (int i = 2; i <= 10000; i++)
	{
		if (is_prime[i])
		{
			for (int j = i * i; j <= 10000; j+=i)
				is_prime[j] = false;
		}
	}

	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int a, b;
		cin >> a >> b;

		vector<int> check(10001, -1);

		queue<int> q;
		q.push(a);
		check[a] = 0;

		while (!q.empty())
		{
			int now = q.front();
			q.pop();

			for(int i=0; i<4; i++)
				for (int j = 0; j <= 9; j++)
				{
					int next = change(now, i, j);
					if (next != -1)
					{
						if (is_prime[next] && check[next] == -1)
						{
							check[next] = check[now] + 1;
							q.push(next);
						}
					}
				}
		}

		cout << check[b] << '\n';
	}
}