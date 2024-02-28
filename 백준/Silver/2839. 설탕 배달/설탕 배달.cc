#include <iostream>
#include <vector>
using namespace std;

int solution(int N)
{
	int answer = 0;
	int sum = N;

	while (sum >0)
	{
		if (sum % 5 != 0) sum -= 3, answer++;
		else
		{
			answer += sum / 5;
			sum = 0;
		}
	}

	return sum == 0 ? answer : -1;
}

int main()
{
	int N;
	cin >> N;

	cout << solution(N);
}