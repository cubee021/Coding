#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sum;
bool check[1501][1501];

void DFS(int a, int b)
{
	if (check[a][b]) return;
	check[a][b] = true;

	int stone[3] = { a, b, sum - a - b };
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			if (stone[i] < stone[j])
			{
				int temp[3] = { a, b, sum - a - b };
				temp[i] += stone[i];
				temp[j] -= stone[i];

				DFS(temp[0], temp[1]);
			}
		}
}

int main()
{
	int A, B, C;
	cin >> A >> B >> C;

	sum = A + B + C;
	if (sum % 3 != 0)
	{
		cout << 0;
		return 0;
	}

	DFS(A, B);

	if (check[sum / 3][sum / 3]) cout << 1;
	else cout << 0;
}