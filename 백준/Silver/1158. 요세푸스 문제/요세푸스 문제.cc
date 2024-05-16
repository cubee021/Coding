#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	queue<int> q;
	int N, K;

	cin >> N >> K;

	for (int i = 1; i <= N; i++) q.push(i);

	cout << "<";

	int cnt = 0;
	while (q.size() > 1)
	{
		if (++cnt == K)
		{
			cout << q.front() << ", ";
			q.pop();

			cnt = 0;
		}
		else
		{
			int temp = q.front();
			q.pop();
			q.push(temp);
		}

	}

	if (!q.empty()) cout << q.front();
	cout<< ">";

}