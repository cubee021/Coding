#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> buttons(10, true);

int possible(int c)
{
	if (c == 0)
	{
		if (!buttons[0]) return 0;
		else return 1;
	}

	int number = 0;
	while (c > 0)
	{
		if (!buttons[c % 10]) return 0;

		number++;
		c /= 10;
	}

	return number; // 숫자버튼 누르는 횟수
}

int main()
{
	int n, m;
	cin >> n;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int broken;
		cin >> broken;
		buttons[broken] = false;
	}

	int answer = n - 100; // 정답의 최대값
	if (answer < 0) answer = -answer;

	for (int i = 0; i <= 1000000; i++)
	{
		int c = i;
		int number = possible(c);
		if (number > 0) // 0은 false, true면 숫자버튼 횟수
		{
			int plusMinus = c - n;

			if (plusMinus < 0) plusMinus = -plusMinus;
			if (answer > number + plusMinus) answer = number + plusMinus;
		}
	}

	cout << answer;
}