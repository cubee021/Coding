#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<string> DNA(N);
	for (int i = 0; i < N; i++)
		cin >> DNA[i];

	sort(DNA.begin(), DNA.end());

	string s = "";
	for (int i = 0; i < M; i++)
	{
		vector<int> cnt(100, 0);
		for (string d : DNA)
		{
			cnt[d[i]]++;
		}

		char max_char;
		int max_cnt = 0;
		for (int j = 'A'; j <= 'Z'; j++)
		{
			if (max_cnt < cnt[j])
			{
				max_char = j;
				max_cnt = cnt[j];
			}
		}

		s += max_char;
	}

	int count_sum = 0;
	for (string dna : DNA)
	{
		for (int j = 0; j < M; j++)
			if (s[j] != dna[j]) count_sum++;
	}

	cout << s << '\n' << count_sum;
}