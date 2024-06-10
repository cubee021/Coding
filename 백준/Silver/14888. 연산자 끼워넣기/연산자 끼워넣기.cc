#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> num;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;

		num.push_back(a);
	}

	vector<int> operations; // +, -, *, /
	for (int i = 0; i < 4; i++)
	{
		int b;
		cin >> b;

		for(int j=0; j<b; j++)
			operations.push_back(i);
	}

	int max_res = -1000000000;
	int min_res = 1000000000;
	do {

		int sum = num[0];

		for (int i = 1; i < N; i++)
		{
			if (operations[i - 1] == 0) // +
			{
				sum += num[i];
			}
			else if (operations[i - 1] == 1) // -
			{
				sum -= num[i];
			}
			else if (operations[i - 1] == 2) // *
			{
				sum *= num[i];
			}
			else // /
			{
				sum /= num[i];
			}
		}

		max_res = max(max_res, sum);
		min_res = min(min_res, sum);

	} while (next_permutation(operations.begin(), operations.end()));


	cout << max_res << '\n' << min_res;
}