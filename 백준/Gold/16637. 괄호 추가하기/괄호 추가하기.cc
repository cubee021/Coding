#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int N, answer = INT_MIN;
string s;

int calc(int a, int b, char op)
{
	if (op == '+') return a + b;
	else if (op == '*') return a * b;
	else if (op == '-') return a - b;

	return -1;
}

void DFS(int idx = 0, int sum = 0)
{
	if (idx >= N)
	{
		answer = max(answer, sum);
		return;
	}

	char op = (idx == 0) ? '+' : s[idx - 1];

	if (idx + 2 < N)
	{
		int bracket = calc(s[idx] - '0', s[idx + 2] - '0', s[idx + 1]);
		DFS(idx + 4, calc(sum, bracket, op));
	}

	DFS(idx + 2, calc(sum, s[idx] - '0', op));
}


int main()
{
	cin >> N;
	cin >> s;

	DFS();

	cout << answer;
	
}