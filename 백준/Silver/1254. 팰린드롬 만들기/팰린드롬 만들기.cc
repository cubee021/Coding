#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPalindrom(string str)
{
	int cnt = str.length() / 2;

	for (int i = 0; i < cnt; i++)
		if (str[i] != str[str.length() - i - 1])
			return false;

	return true;
}

int main()
{
	string s;
	cin >> s;

	int answer = s.length() * 2 - 1;

	for (int i = 0; i < s.length(); i++)
	{
		string temp = s.substr(i, s.length() - i);
		if (isPalindrom(temp))
		{
			answer = s.length() + i;
			break;
		}
	}
		
	cout << answer;
}