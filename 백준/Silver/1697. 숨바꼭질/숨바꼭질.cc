#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX_N 100001

int main()
{
	int start, end;
	cin >> start >> end;

	vector<int> dist(MAX_N, 0);
	vector<bool> check(MAX_N, false);

	queue<int> q;
	q.push(start);
	dist[start] = 0;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (cur == end) break;

		if (cur + 1 < MAX_N)
		{
			if (!check[cur + 1])
			{
				dist[cur + 1] = dist[cur] + 1;
				check[cur + 1] = true;
				q.push(cur + 1);
			}
		}

		if (cur - 1 >= 0)
		{
			if (!check[cur - 1])
			{
				dist[cur - 1] = dist[cur] + 1;
				check[cur - 1] = true;
				q.push(cur - 1);
			}
		}

		if (cur * 2 < MAX_N)
		{
			if (!check[cur * 2])
			{
				dist[cur * 2] = dist[cur] + 1;
				check[cur * 2] = true;
				q.push(cur * 2);
			}
		}
	}

	cout << dist[end];
}