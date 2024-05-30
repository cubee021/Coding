#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int answer = 2147483647;
vector<int> team1;
vector<int> team2;

void get_min(vector<vector<int>>& power, vector<int> team1, vector<int> team2, int idx = 0)
{
	int n = power.size();

	if (idx == n)
	{
		if (team1.size() > n / 2 || team2.size() > n / 2) return;

		int sum1 = 0;
		int sum2 = 0;

		for (int i = 0; i < team1.size()-1; i++)
			for (int j = i+1; j < team1.size(); j++)
				if(i != j) sum1 += power[team1[i]][team1[j]] + power[team1[j]][team1[i]];

		for (int i = 0; i < team2.size()-1; i++)
			for (int j = i+1; j < team2.size(); j++)
				if (i != j) sum2 += power[team2[i]][team2[j]] + power[team2[j]][team2[i]];

		answer = min(answer, abs(sum1 - sum2));
		
		return;
	}

	team1.push_back(idx);
	get_min(power, team1, team2, idx + 1);
	team1.pop_back();

	team2.push_back(idx);
	get_min(power, team1, team2, idx + 1);
	team2.pop_back();
}

int main()
{
	int N;
	cin >> N;

	vector<vector<int>> power(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int a;
			cin >> a;

			power[i][j] = a;
		}
	}

	get_min(power, team1, team2);

	cout << answer;
}