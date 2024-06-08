#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int S;
	cin >> S;

	vector<vector<int>> dist(1001, vector<int>(1001, -1)); // time
	queue<pair<int, int>> q;

	q.push({ 1, 0 }); // cnt, clip
	dist[1][0] = 0;

	while (!q.empty())
	{
		int cnt = q.front().first;
		int clip = q.front().second;
		q.pop();

		if (dist[cnt][cnt] == -1)
		{
			q.push({ cnt, cnt });
			dist[cnt][cnt] = dist[cnt][clip] + 1;
		}

		if (clip > 0 && cnt + clip<=S)
		{
			if (dist[cnt + clip][clip] == -1)
			{
				q.push({ cnt + clip, clip });
				dist[cnt + clip][clip] = dist[cnt][clip] + 1;
			}
		}

		if (cnt > 0)
		{
			if (dist[cnt - 1][clip] == -1)
			{
				q.push({ cnt - 1, clip });
				dist[cnt - 1][clip] = dist[cnt][clip] + 1;
			}
		}
	}

	int ans = -1;
	for (int i = 0; i <= S; i++)
	{
		if (dist[S][i] != -1)
		{
			if (ans == -1 || ans > dist[S][i]) ans = dist[S][i];
		}
	}

	cout << ans;
	
}