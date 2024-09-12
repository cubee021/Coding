#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, answer = -1;
int S[10];
int B[10];

void BFS(int idx = 0, int s_sum = 1, int b_sum = 0)
{
	if (idx == N)
	{
		if (s_sum == 1 && b_sum == 0) return;

		int temp = abs(s_sum - b_sum);
		if (answer == -1 || answer > temp)
			answer = temp;

		return;
	}

	BFS(idx + 1, s_sum * S[idx], b_sum + B[idx]);
	BFS(idx + 1, s_sum, b_sum);
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> S[i] >> B[i];

	BFS();

	cout << answer;
}