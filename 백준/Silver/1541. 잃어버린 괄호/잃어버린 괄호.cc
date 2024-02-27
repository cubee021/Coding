#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
	int answer = 0;
	stack<int> stack;
	string number = "";

	for (char c : s)
	{
		if (isdigit(c)) number += c;
		else
		{
			if(number != "")
				stack.push(stoi(number));

			number = "";

			if (c == '-') number += c;
		}
	}
	if (number != "")
		stack.push(stoi(number));


	int sum = 0;
	while (!stack.empty())
	{
		if (stack.top() >= 0)
		{
			sum += stack.top();
		}
		else
		{
			sum -= stack.top();
			answer -= sum;

			sum = 0;
		}

		stack.pop();
	}
	answer += sum;

	return answer;
}

int main()
{
	string s = "";
	cin >> s;

	cout << solution(s);
}