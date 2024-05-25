#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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
		answer[idx] = i;
		sequence(N, M, idx + 1);
	}
}

int main()
{
	int N, M;
	cin >> N >> M;

	sequence(N, M);
}