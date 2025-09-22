#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	int N;
	cin >> N;

	priority_queue<unsigned int, vector<unsigned int>, greater<>> pq;

	for (int n = 0; n < N; n++)
	{
		unsigned int x;
		cin >> x;

		if (x > 0)
		{
			pq.push(x);
		}
		else
		{
			if (pq.empty())
			{
				cout << 0 << '\n';
				continue;
			}

			cout << pq.top() <<'\n';
			pq.pop();
		}
	}
}