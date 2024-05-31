#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string max_num = "0";
string min_num = "999999999";

vector<bool> used(10, false);

void find_number(string& s, string answer="", int idx = 0)
{
	if (idx == s.length())
	{
		max_num = max(max_num, answer);
		min_num = min(min_num, answer);

		return;
	}

	if (answer.size() == 0)
	{
		for (int i = 0; i <= 9; i++)
		{
			string temp = answer;
			temp += (i + '0');

			used[i] = true;
			find_number(s, temp, idx);
			used[i] = false;
		}
	}
	else
	{
		int p = answer[answer.size() - 1] - '0';

		if (s[idx] == '>')
		{
			for (int i = 0; i < p; i++)
			{
				if (used[i]) continue;

				string temp = answer;
				temp += (i + '0');

				used[i] = true;
				find_number(s, temp, idx+1);
				used[i] = false;
			}
		}
		else
		{
			for (int i = p+1; i <= 9; i++)
			{
				if (used[i]) continue;

				string temp = answer;
				temp += (i + '0');

				used[i] = true;
				find_number(s, temp, idx + 1);
				used[i] = false;
			}
		}
	}
}

int main()
{
	int k;
	cin >> k;

	string s = "";
	for (int i = 0; i < k; i++)
	{
		char a;
		cin >> a;

		s += a;
	}

	find_number(s);

	cout << max_num << '\n' << min_num;
}