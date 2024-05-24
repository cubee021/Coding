#include <iostream>
#include <vector>
using namespace std;

vector<int> used(10, false);
vector<int> answer(10, 0);

void sequence(int N, int M, int idx = 0)
{
	if (idx == M)
	{
		for (int i = 0; i < idx; i++) cout << answer[i] << " ";
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (used[i]) continue;

		used[i] = true;
		answer[idx] = i;
		sequence(N, M, idx + 1);
		used[i] = false;
	}
}

int main()
{
	int N, M;
	cin >> N >> M;

	sequence(N, M);
}