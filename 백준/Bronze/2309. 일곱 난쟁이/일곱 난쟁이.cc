#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> heights;
	int sum = 0;
	for (int i = 0; i < 9; i++)
	{
		int h;
		cin >> h;

		heights.push_back(h);
		sum += h;
	}

	sort(heights.begin(), heights.end());

	for (int i = 0; i < heights.size(); i++)
	{
		for (int j = i + 1; j < heights.size(); j++)
		{
			int temp = sum - heights[i] - heights[j];
			if (temp == 100)
			{
				for (int k = 0; k < heights.size(); k++)
					if (k != i && k != j) cout << heights[k] << endl;

				return 0;
			}
		}
	}
}