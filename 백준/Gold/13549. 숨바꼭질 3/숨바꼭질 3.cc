#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX_SIZE 100001

int main()
{
	int N, K;
	cin >> N >> K;

	vector<bool> visited(MAX_SIZE, false);
	deque<pair<int, int>> dq;

	dq.push_back({N, 0}); // cur, time
	visited[N] = true;

	while (!dq.empty())
	{
		int cur = dq.front().first;
		int time = dq.front().second;
		dq.pop_front();

		if (cur == K)
		{
			cout << time;
			break;
		}

		if (cur * 2 < MAX_SIZE && !visited[cur * 2])
		{
			dq.push_front({cur*2, time});
			visited[cur * 2] = true;
		}

		if (cur - 1 >= 0 && !visited[cur - 1])
		{
			dq.push_back({ cur - 1 , time + 1});
			visited[cur - 1] = true;
		}

		if (cur + 1 < MAX_SIZE && !visited[cur + 1])
		{
			dq.push_back({ cur + 1 , time + 1 });
			visited[cur + 1] = true;
		}
	}

}