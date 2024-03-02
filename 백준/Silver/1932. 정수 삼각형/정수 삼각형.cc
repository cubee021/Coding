#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>>& v)
{
	for (int i = v.size() - 1; i >= 0; i--)
	{
		for (int j = 0; j < v[i].size()-1; j++)
		{
			v[i - 1][j] += max(v[i][j], v[i][j + 1]);
		}
	}

	return v[0][0];
}

int main()
{
	vector<vector<int>> v;
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		vector<int> temp;
		for (int j = 0; j < i; j++)
		{
			int k;
			cin >> k;

			temp.push_back(k);
		}

		v.push_back(temp);
	}

	cout << solution(v);
}