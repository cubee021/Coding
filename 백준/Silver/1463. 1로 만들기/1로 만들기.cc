#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n)
{
	vector<int> answer{0, 1, 1};
	vector<int> temp;

	for (int i = 4; i <= n; i++)
	{
		if (i % 3 == 0) temp.push_back(1 + answer[(i / 3) - 1]);

		if (i % 2 == 0) temp.push_back(1 + answer[(i / 2) - 1]);

		temp.push_back(1 + answer[i - 2]);

		answer.push_back(*min_element(temp.begin(), temp.end()));
		temp.clear();
	}

	return answer[n-1];
}

int main()
{
	int n;
	cin >> n;

	cout << solution(n);
}