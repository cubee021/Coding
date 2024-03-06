#include <iostream>
#include <vector>
using namespace std;

int solution(int N, int M)
{
	int answer = 1;
	int cnt = 1;
	for (int i = M; i > M-N; i--)
	{
		answer *= i;
		answer /= cnt;

		cnt++;
	}

	return answer;
}

int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int N, M;
		cin >> N >> M;

		cout << solution(N, M)<<endl;
	}
}