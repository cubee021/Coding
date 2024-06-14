#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> num;
unordered_map<int, int> operations; // +, -, *, /

int max_ = -1000000000;
int min_ = 1000000000;

void DFS(int& sum, int idx = 1)
{
	if (idx == num.size())
	{
		max_ = max(max_, sum);
		min_ = min(min_, sum);

		return;
	}

	for (int i=0; i<4; i++)
	{
		int temp = sum;

		if (operations[i] > 0)
		{
			int op = i;
			operations[i]--;

			if (op == 0) temp += num[idx];
			else if (op == 1) temp -= num[idx];
			else if (op == 2) temp *= num[idx];
			else temp /= num[idx];

			DFS(temp, idx + 1);

			operations[i]++;
		}
	}
}

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;

		num.push_back(a);
	}

	for (int i = 0; i < 4; i++)
	{
		int b;
		cin >> b;

		operations[i] = b;
	}

	DFS(num[0]);

	cout << max_ << '\n' << min_;
}