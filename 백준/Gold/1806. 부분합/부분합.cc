#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, S;
	cin >> N >> S;

	vector<int> arr;
	for (int i = 0; i < N; i++)
	{
		int a; 
		cin >> a;
		arr.push_back(a);
	}
	arr.push_back(-1);

	int answer = N+1;
	int l = 0, r = 0, sum = arr[l];
	while (l <= r && r < N)
	{
		if (sum >= S)
		{
			answer = min(answer, r - l + 1);

			sum -= arr[l++];
		}
		else
		{
			sum += arr[++r];
		}
	}
    if(answer == N+1) answer = 0;

	cout << answer;
}