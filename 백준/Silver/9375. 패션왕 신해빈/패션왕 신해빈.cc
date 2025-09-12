#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	int T;
	cin >> T;

	for(int t=0; t<T; t++)
	{
		int N;
		cin >> N;

		unordered_map<string, int> map;

		for (int i = 0; i < N; i++)
		{
			string name, type;
			cin >> name >> type;

			map[type]++;
		}

		int result = 1;
		for (auto m : map)
		{
			result *= (m.second + 1);
		}

		cout << result - 1 << '\n';
	}

}