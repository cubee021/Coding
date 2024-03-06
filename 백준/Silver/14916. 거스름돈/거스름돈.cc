#include <iostream>
#include <vector>
using namespace std;

int solution(int n)
{
	int answer = 0;
	
	while (n >= 0)
	{
		if (n % 5 == 0)
		{
			answer += n / 5;
			n = 0;
			break;
		}
		else
		{
			answer++;
			n -= 2;
		}
	}

	return n != 0 ? -1 : answer;
}

int main()
{
	int n;
	cin >> n;

	cout << solution(n);
}