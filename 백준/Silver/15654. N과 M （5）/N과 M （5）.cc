#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> used(10, false);
vector<int> answer(10, 0);

void sequence(vector<int>& num, int N, int M, int idx = 0)
{
	if (idx == M)
	{
		for (int i = 0; i < idx; i++) cout << answer[i] << " ";
		cout << '\n';
		return;
	}

	for (int i=0; i<num.size(); i++)
	{
		if (used[i]) continue;

		answer[idx] = num[i];
		used[i] = true;
		sequence(num, N, M, idx + 1);
		used[i] = false;
	}
}

int main()
{
	int N, M;
	cin >> N >> M;

	vector<int> num;
	for (int i = 0; i < N; i++)
	{
		int k;
		cin >> k;
		num.push_back(k);
	}

	sort(num.begin(), num.end());

	sequence(num ,N, M);
}