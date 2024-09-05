#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int answer = -1;

void calc(vector<int>& B, int x, int y, int idx, int cnt)
{
	if (idx == N)
	{
		if (answer == -1 || answer > cnt) answer = cnt;
		return;
	}

	int temp = y - x;

	if (B[idx] - y == temp) calc(B, y, B[idx], idx + 1, cnt);
	else if (B[idx] + 1 - y == temp) calc(B, y, B[idx] + 1, idx + 1, cnt + 1);
	else if (B[idx] - 1 - y == temp) calc(B, y, B[idx] - 1, idx + 1, cnt + 1);
	else return;
}

int main()
{
	cin >> N;

	vector<int> B(N, 0);
	for (int i = 0; i < N; i++)
		cin >> B[i];

	if (N == 1)
	{
		cout << 0;
		return 0;
	}

	calc(B, B[0], B[1], 2, 0);
	calc(B, B[0], B[1] + 1, 2, 1);
	calc(B, B[0], B[1] - 1, 2, 1);

	calc(B, B[0] + 1, B[1], 2, 1);
	calc(B, B[0] + 1, B[1] + 1, 2, 2);
	calc(B, B[0] + 1, B[1] - 1, 2, 2);

	calc(B, B[0] - 1, B[1], 2, 1);
	calc(B, B[0] - 1, B[1] + 1, 2, 2);
	calc(B, B[0] - 1, B[1] - 1, 2, 2);

	cout << answer;
}