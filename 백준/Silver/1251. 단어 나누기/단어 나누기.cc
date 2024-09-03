#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	string s;
	cin >> s;

	string answer = "";
	int n = s.length();

	for (int i = 1; i <= n-2; i++)
	{
		for (int j = 1; j <= n-2; j++)
		{
			if (i + j >= n) break;

			string front = s.substr(0, i);
			string mid = s.substr(i, j);
			string back = s.substr(i + j);

			reverse(front.begin(), front.end());
			reverse(mid.begin(), mid.end());
			reverse(back.begin(), back.end());

			string result = front + mid + back;

			if (answer == "") answer = result;
			else
			{
				if (answer > result)
				{
					answer = result;
				}
			}
		}
	}

	cout << answer;
}