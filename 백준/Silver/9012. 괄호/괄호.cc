#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main()
{
	int T;
	cin>>T;

	for (int t = 0; t < T; t++)
	{
		stack<char> stack;
		bool ok = true;

		string input;
		cin>>input;

		for (char c : input)
		{
			if (c == '(')
				stack.push(c);
			else
			{
				if (!stack.empty())
				{
					stack.pop();
				}
				else
				{
					ok = false;
					break;
				}
			}
		}

		ok && stack.empty() ? cout << "YES\n" : cout << "NO\n";
	}
}