#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, answer = 0;

int lose[20];
int gain[20];

void dfs(int idx = 0, int health = 100, int happy = 0)
{
	if (health <= 0) return;
	if (idx == N)
	{
		answer = max(answer, happy);
		return;
	}

	dfs(idx + 1, health - lose[idx], happy + gain[idx]);
	dfs(idx + 1, health, happy);

}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> lose[i];

	for (int i = 0; i < N; i++)
		cin >> gain[i];

	dfs();

	cout << answer;
}