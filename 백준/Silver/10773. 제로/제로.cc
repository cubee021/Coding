#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main()
{
	int K;
	cin >> K;

	stack<int> stack;

	for (int i = 0; i < K; i++)
	{
		int n;
		cin >> n;

		if (n != 0)
			stack.push(n);
		else
			stack.pop();
	}

	int answer = 0;
	while (!stack.empty())
	{
		answer += stack.top();
		stack.pop();
	}
	
	cout << answer;
}