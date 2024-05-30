#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int answer = 0;

void max_profit(vector<vector<int>>& plan, int idx = 0, int sum = 0)
{
	if (idx == plan.size())
	{
		answer = max(answer, sum);
		return;
	}

	if (idx > plan.size()) return;

	max_profit(plan, idx+plan[idx][0], sum+plan[idx][1]);
	max_profit(plan, idx+1, sum);
}

int main()
{
	int N;
	cin >> N;

	vector<vector<int>> plan;
	for (int i = 0; i < N; i++)
	{
		int t, p; // 기간, 금액
		cin >> t >> p;

		plan.push_back({ t, p });
	}

	max_profit(plan);

	cout << answer;
}