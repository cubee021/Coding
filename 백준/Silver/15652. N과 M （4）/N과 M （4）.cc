#include <iostream>
#include <vector>
using namespace std;

vector<int> answer(10, 0);

void sequence(int N, int M, int prev = 1, int idx = 0)
{
	if (idx == M)
	{
		for (int i = 0; i < idx; i++) cout << answer[i] << " ";
		cout << '\n';
		return;
	}

	for (int i = prev; i <= N; i++)
	{
		if (prev > i) continue;

		answer[idx] = i;
		sequence(N, M, i, idx + 1);
	}
}

int main()
{
	int N, M;
	cin >> N >> M;

	sequence(N, M);
}