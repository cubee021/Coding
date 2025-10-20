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

	int M;
	cin >> M;

	vector<int> S(21, 0);
	for (int m = 0; m < M; m++)
	{
		string s;
		cin >> s;

		if (s == "add" || s == "remove" || s == "check" || s == "toggle")
		{
			int x;
			cin >> x;

			if (s == "add") S[x] = 1;
			else if (s == "remove") S[x] = 0;
			else if (s == "check") cout << S[x] << '\n';
			else if (s == "toggle") S[x] = (S[x] + 1) % 2;
		}
		else
		{
			if (s == "all")
			{
				for (int i = 1; i <= 20; i++)
					S[i] = 1;
			}
			else if (s == "empty")
			{
				for (int i = 1; i <= 20; i++)
					S[i] = 0;
			}
		}
	}
}