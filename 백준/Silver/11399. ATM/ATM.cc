#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> v)
{
	int answer = 0;
	sort(v.begin(), v.end(), greater<int>());

	for (int i = 1; i <= v.size(); i++)
		answer += v[i - 1] * i;

	return answer;
}

int main()
{
	vector<int> v;
	int length;
	cin >> length;

	for (int i = 0; i < length; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	cout << solution(v);
}