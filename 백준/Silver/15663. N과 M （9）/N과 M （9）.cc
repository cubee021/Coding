#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> answer(10, 0);

void sequence(vector<int>& num, vector<int>& cnt, int M, int idx = 0)
{
	if (idx == M)
	{
		for (int i = 0; i < idx; i++) cout << answer[i] << " ";
		cout << '\n';
		return;
	}

	for (int i=0; i<num.size(); i++)
	{
		if (cnt[i] > 0)
		{
			cnt[i]--;
			answer[idx] = num[i];
			sequence(num, cnt, M, idx + 1);
			cnt[i]++;
		}
	}
}

int main()
{
	int N, M;
	cin >> N >> M;

	map<int, int> map;
	for (int i = 0; i < N; i++)
	{
		int k;
		cin >> k;
		
		map[k]++;
	}

	vector<int> num;
	vector<int> cnt;

	for (auto m : map)
	{
		num.push_back(m.first);
		cnt.push_back(m.second);
	}


	sequence(num, cnt, M);
}