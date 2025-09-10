#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	int N, M;
	cin >> N >> M;

	map<int, string> num;
	map<string, int> name;
	
	for (int i = 1; i <= N; i++)
	{
		string s;
		cin >> s;

		num[i] = s;
		name[s] = i;
	}

	for (int t = 0; t < M; t++)
	{
		string s;
		cin >> s;

		if (isalpha(s[0]))
		{
			cout << name[s] << '\n';
		}
		else
		{
			cout << num[stoi(s)] << '\n';
		}
	}
}