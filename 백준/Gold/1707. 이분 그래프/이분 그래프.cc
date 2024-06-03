#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int K;
	cin >> K;

	for (int t = 0; t < K; t++)
	{
		int V, E;
		cin >> V >> E;

		vector<vector<int>> edge(V+1, vector<int>());
		vector<int> check(V+1, -1);
		for (int i = 0; i < E; i++)
		{
			int u, v;
			cin >> u >> v;

			edge[u].push_back(v);
			edge[v].push_back(u);
		}

		queue<int> q;
		bool ok = true;

		for (int i = 1; i <= V; i++)
		{
			if (check[i] != -1) continue;

			q.push(i);
			check[i] = 0;

			while (!q.empty())
			{
				int current = q.front();
				vector<int> next = edge[current];
				q.pop();

				for (int e : next)
				{
					if (check[e] == 0 && check[current] == 0)
					{
						ok = false;
						break;
					}

					if (check[e] == 1 && check[current] == 1)
					{
						ok = false;
						break;

					}

					if (check[e] == -1)
					{
						if (check[current] == 0) check[e] = 1;
						else check[e] = 0;

						q.push(e);
					}
				}

				if (!ok) break;
			}
		}
		
		if (ok) cout << "YES\n";
        else cout << "NO\n";
	}
}