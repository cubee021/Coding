#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> arr(5);
	int answer = -1;
	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];

		if (answer == -1 || answer > arr[i]) answer = arr[i];
	}

	int cnt = 0;
	answer--;

	while (cnt < 3)
	{
		answer++;
		cnt = 0;

		for (int i = 0; i < 5; i++)
			if (answer % arr[i] == 0) cnt++;
	}

	cout << answer;
}