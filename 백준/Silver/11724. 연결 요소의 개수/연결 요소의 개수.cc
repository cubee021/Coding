#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& edge, vector<int>& check, int node)
{
	vector<int> next = edge[node];
	for (int i : next)
	{
		if (!check[i])
		{
			check[i] = true;
			dfs(edge, check, i);
		}
	}

	return;
}

int main()
{
	int N, M, answer = 0;
	cin >> N >> M;

	vector<vector<int>> edge(N+1, vector<int>());
	vector<int> check(N + 1, false);
	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;

		edge[u].push_back(v);
		edge[v].push_back(u);
	}

	for (int i = 1; i <= N; i++)
	{
		if (!check[i])
		{
			dfs(edge, check, i);
			answer++;
		}
	}

	cout << answer;
}