#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
int answer = 0;

void BFS(vector<vector<int>>& node)
{
	queue<int> q;
	q.push(1);

	vector<int> visited(N + 1, -1);
	visited[1] = 0;

	while (q.size())
	{
		int cur = q.front();
		q.pop();

		for (auto next : node[cur])
		{
			if (visited[next] != -1) continue;

			q.push(next);
			visited[next] = 0;

			answer++;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> N >> M;

	vector<vector<int>> node(N+1);
	for (int i = 0; i < M; i++)
	{
		int l, k;
		cin >> l >> k;

		node[l].push_back(k);
		node[k].push_back(l);
	}

	BFS(node);

	cout << answer;
}