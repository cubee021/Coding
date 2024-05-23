#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int M, N, x, y;
		cin >> M >> N >> x >> y;

		x--, y--;

		bool found = false;
		for (int n = x ; n < M * N; n += M)
		{
			if (n%N == y)
			{
				cout << n + 1 << endl;
				found = true;
				break;
			}
		}

		if(!found) cout << -1 << endl;
	}
}