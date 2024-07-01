#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int ladder[101];
int snake[101];

void BFS(vector<bool>& check)
{
	queue<pair<int, int>> q;
	q.push({1, 0}); // cur, cnt

	while (!q.empty())
	{
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == 100)
		{
			cout << cnt;
			return;
		}

		for (int dice = 1; dice <= 6; dice++)
		{
			if (cur + dice > 100) continue;
			if (check[cur + dice]) continue;

			if (ladder[cur+dice] != 0)
			{
				int next = ladder[cur + dice];

				check[next] = true;
				q.push({ next, cnt + 1 });
			}
			else if (snake[cur+dice] != 0)
			{
				int next = snake[cur + dice];

				check[next] = true;
				q.push({ next, cnt + 1 });
			}
			else
			{
				int next = cur + dice;

				check[next] = true;
				q.push({ next, cnt + 1 });
			}
		}
	}
}

int main()
{
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;

		ladder[x] = y;
	}

	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;

		snake[u] = v;
	}

	vector<bool> check(101, false);

	BFS(check);

}