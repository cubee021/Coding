#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> mushroom(10);

	for (int i = 0; i < 10; i++)
		cin >> mushroom[i];

	int answer = 0;
	int sum = 0;
    
	for (int i = 0; i < 10; i++)
	{
        int temp = sum;
        sum += mushroom[i];

		if (abs(temp - 100) >= abs(sum - 100))
			answer = sum;
	}
	cout << answer;
}