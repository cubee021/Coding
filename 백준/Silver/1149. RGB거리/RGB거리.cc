#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> houses)
{
	int answer = 0;

	for (int i = 0; i < houses.size()-1; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (j == 0) houses[i + 1][0] += min(houses[i][1], houses[i][2]);
			else if(j == 1) houses[i + 1][1] += min(houses[i][0], houses[i][2]);
			else houses[i + 1][2] += min(houses[i][0], houses[i][1]);
		}
	}

	return *min_element(houses[houses.size()-1].begin(), houses[houses.size() - 1].end());
}

int main()
{
	vector<vector<int>> houses;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		vector<int> cost;
		for (int i = 0; i < 3; i++)
		{
			int temp;
			cin >> temp;

			cost.push_back(temp);
		}
		houses.push_back(cost);
	}

	cout << solution(houses);
}