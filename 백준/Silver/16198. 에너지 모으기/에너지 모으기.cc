#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int DFS(vector<int>& marbles)
{
	int n = marbles.size();
	int answer = 0;

	if (n == 2) return 0;

	for (int i = 1; i < n - 1; i++)
	{
		int sum = marbles[i - 1] * marbles[i + 1];

		vector<int> temp = marbles;
		temp.erase(temp.begin() + i);

		sum += DFS(temp);

		answer = max(answer, sum);
	}

	return answer;
}

int main()
{
	int N;
	cin >> N;

	vector<int> marbles;
	for (int i = 0; i < N; i++)
	{
		int energy;
		cin >> energy;

		marbles.push_back(energy);
	}

	cout << DFS(marbles);
}