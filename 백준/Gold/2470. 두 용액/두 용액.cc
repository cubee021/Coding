#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> solution(vector<int>& v)
{
	vector<int> answer(2, 0);

	int left = 0;
	int right = v.size() - 1;
	int min = 2000000001;

	sort(v.begin(), v.end());

	while (left != right)
	{
		int sum = v[left] + v[right];

		if (abs(sum) < abs(min))
		{
			min = sum;
			answer[0] = v[left];
			answer[1] = v[right];
		}

		if (sum > 0) right--;
		else if (sum < 0) left++;
		else break;
	}
	
	return answer;
}

int main()
{
	vector<int> v;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;

		v.push_back(temp);
	}

	vector<int> answer = solution(v);
	cout << answer[0] << " " << answer[1];
}