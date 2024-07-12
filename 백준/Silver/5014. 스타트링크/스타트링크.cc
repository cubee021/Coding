#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	int F, S, G, U, D; // 총 층수, 현재층, 목표층, 업, 다운
	cin >> F >> S >> G >> U >> D;

	vector<int> check(1000001, -1);
	queue<int> q;

	q.push(S);
	check[S] = 0;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (cur == G)
		{
			cout << check[cur];
			return 0;
		}

		if (cur + U >= 1 && cur + U <= F)
		{
			if (check[cur + U] == -1)
			{
				q.push(cur + U);
				check[cur + U] = check[cur] + 1;
			}
		}

		if (cur - D >= 1 && cur - D <= F)
		{
			if (check[cur - D] == -1)
			{
				q.push(cur - D);
				check[cur - D] = check[cur] + 1;
			}
		}
	}

	cout << "use the stairs";

}