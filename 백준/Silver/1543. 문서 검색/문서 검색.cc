#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);

	int answer = 0;
	while (!s1.empty())
	{
		int found_idx = s1.find(s2);

		if (found_idx == string::npos) break;

		answer++;

		int next_start = found_idx + s2.length();
		s1 = s1.substr(next_start);
	}

	cout << answer;
}