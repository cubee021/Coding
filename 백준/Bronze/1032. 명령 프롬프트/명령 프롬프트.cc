#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int N;
	cin >> N;

	string answer = "";
	vector<string> prompts(N);

	for (int i = 0; i < N; i++)
	{
		cin >> prompts[i];
	}

	for (int i = 0; i < prompts[0].length(); i++)
	{
		bool isSame = true;
		char temp = prompts[0][i];

		for (int j = 1; j < N; j++)
		{
			if (temp != prompts[j][i])
			{
				isSame = false;
				break;
			}
		}

		isSame ? answer += temp : answer += '?';
	}

	cout << answer;
}