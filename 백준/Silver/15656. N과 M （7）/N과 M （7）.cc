#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> answer(10, 0);

void sequence(vector<int>& num, int N, int M, int prev = 0, int idx = 0)
{
	if (idx == M)
	{
		for (int i = 0; i < idx; i++) cout << answer[i] << " ";
		cout << '\n';
		return;
	}

	for (int i=0; i<num.size(); i++)
	{
		answer[idx] = num[i];
		sequence(num, N, M, i,idx + 1);
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