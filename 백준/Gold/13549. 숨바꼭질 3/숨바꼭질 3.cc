#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX_SIZE 100001

int main()
{
	int N, K;
	cin >> N >> K;

	vector<int> visited(MAX_SIZE, -1);
	deque<int> dq;

	dq.push_back(N);
	visited[N] = 1;

	while (!dq.empty())
	{
		int cur = dq.front();
		dq.pop_front();

		if (cur == K)
		{
			cout << visited[K] - 1;
			break;
		}

		if (cur * 2 < MAX_SIZE && visited[cur * 2] == -1)
		{
			dq.push_front(cur * 2);
			visited[cur * 2] = visited[cur];
		}
        
        if (cur - 1 >= 0 && visited[cur - 1] == -1)
		{
			dq.push_back(cur - 1);
			visited[cur - 1] = visited[cur] + 1;
		}
        
		if (cur + 1 < MAX_SIZE && visited[cur + 1] == -1)
		{
			dq.push_back(cur + 1);
			visited[cur + 1] = visited[cur] + 1;
		}
	}

}