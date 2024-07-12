#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

#define MAX_ 1000000001

int main()
{
	long long s, t;
	cin >> s >> t;

	set<long long> check;
	queue<pair<long long, string>> q;

	q.push({ s, "" });
	check.insert(s);

	while (!q.empty())
	{
		long long n = q.front().first;
		string str = q.front().second;
		q.pop();

		if (n == t)
		{
			if (str.empty()) str = "0";

			cout << str;
			return 0;
		}

		if (0 <= n * n && n * n <= MAX_ && check.count(n * n) == 0)
		{
			q.push({ n * n, str + "*" });
			check.insert(n * n);
		}
		if (0 <= n + n && n + n <= MAX_ && check.count(n + n) == 0)
		{
			q.push({ n + n, str + "+" });
			check.insert(n + n);
		}
		if (0 <= n - n && n - n <= MAX_ && check.count(n - n) == 0)
		{
			q.push({ n * n, str + "-" });
			check.insert(n - n);
		}
		if (n != 0 && 0 <= n / n && n / n <= MAX_ && check.count(n / n) == 0)
		{
			q.push({ n / n, str + "/" });
			check.insert(n / n);
		}

	}

	cout << -1;

}