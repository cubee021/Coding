#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;

	long long answer = 0;
	for (int start = 1, length = 1; start <= N; start *= 10, length++)
	{
		int end = start * 10 - 1;

		if (end > N) end = N;

		answer += (long long)(end - start + 1) * length;
	}

	cout << answer;
}