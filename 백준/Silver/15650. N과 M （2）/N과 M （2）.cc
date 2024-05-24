#include <iostream>
#include <vector>
using namespace std;

vector<int> answer(10, 0);

void sequence(int N, int M, int start = 1, int cnt = 0)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++) cout << answer[i] << " ";
		cout << endl;
		return;
	}

	for (int i = start; i <= N; i++)
	{
		answer[cnt] = i;
		sequence(N, M, i+1, cnt + 1);
	}
}

int main()
{
	int N, M;
	cin >> N >> M;

	sequence(N, M);
}