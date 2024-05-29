#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(string& s)
{
	int cnt1 = 0; // 모음
	int cnt2 = 0; // 자음

	for (char c : s)
	{
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cnt1++;
		else cnt2++;
	}

	return cnt1 >= 1 && cnt2 >= 2 ? true : false;
}

void password(vector<char>& alphabet, int L, int idx = 0, string s = "")
{
	if (s.length() == L)
	{
		if (check(s))
		{
			cout << s << '\n';
		}
		return;
	}

	if (idx >= alphabet.size()) return;

	password(alphabet, L, idx+1, s + alphabet[idx]);
	password(alphabet, L, idx+1, s);
}

int main()
{
	int L, C;
	cin >> L >> C;

	vector<char> alphabet;
	for (int i = 0; i < C; i++)
	{
		char a;
		cin >> a;

		alphabet.push_back(a);
	}

	sort(alphabet.begin(), alphabet.end());

	password(alphabet, L);
}