#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int>& A, int& M)
{
	int answer = 0;

	int start = 0;
	int end = 0;
	int sum = A[0];

	while (end < A.size())
	{
		if (sum < M)
		{
			end++;
			if(end < A.size())
				sum += A[end];
		}
		else if (sum > M)
		{
			sum -= A[start];
			start++;
		}
		else if (sum == M)
		{
			answer++;

			sum -= A[start];
			start++;
			end++;
			if(end < A.size())
				sum += A[end];
		}
	}

	return answer;
}

int main()
{
	vector<int> A;
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;

		A.push_back(temp);
	}

	cout << solution(A, M);
}