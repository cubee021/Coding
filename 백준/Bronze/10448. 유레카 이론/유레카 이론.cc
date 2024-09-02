#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> T(1001);
	for (int i = 1; i <= 1000; i++)
	{
		int temp = (i * (i + 1)) / 2;
		T[i] = temp;
	}

	int t;
	cin >> t;

	for (int test = 0; test < t; test++)
	{
		int K;
		cin >> K;

		if (K < 3)
		{
			cout << 0 << '\n';
			continue;
		}

		bool found = false;

		for (int i = 1; i < T.size() - 2; i++)
		{
			for (int j = i; j < T.size() - 1; j++)
			{
				for (int k = j; k < T.size(); k++)
				{
					bool over3 = false;

					if (K == T[i] + T[j] + T[k])
					{
						cout << 1 << '\n';

						found = true;
						break;
					}
					
					if (K < T[i] + T[j] + T[k]) break;
				}
				if (found || K < T[i] + T[j]) break;
			}
			if (found || K < T[i]) break;
		}

		if (!found) cout << 0 << '\n';
	}
}