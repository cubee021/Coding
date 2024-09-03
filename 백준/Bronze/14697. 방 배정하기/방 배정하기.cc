#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int A, B, C, N;
	cin >> A >> B >> C >> N;

	for (int i = 0; i <= N; i += A)
	{
		for (int j = 0; j <= N; j += B)
		{
			for (int k = 0; k <= N; k += C)
			{
				if (i + j + k > N) break;
				else if (i + j + k == N)
				{
					cout << 1;
					return 0;
				}
			}
		}
	}

	cout << 0;
}