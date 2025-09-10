#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	map<string, string> map;
	for (int i = 0; i < N; i++)
	{
		string website = "";
		string password = "";

		cin >> website >> password;
		
		map[website] = password;
	}

	for (int t = 0; t < M; t++)
	{
		string s;
		cin >> s;

		cout << map[s] << '\n';
	}

}