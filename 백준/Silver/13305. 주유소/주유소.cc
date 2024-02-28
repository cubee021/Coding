#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> cities, vector<int> roads)
{
	int answer = 0;
	int min_cost = cities[0];
	int road_sum = 0;

	for (int i = 0; i < cities.size() - 1; i++)
	{
		road_sum += roads[i];

		if (min_cost > cities[i+1])
		{
			answer += road_sum * min_cost;
			min_cost = cities[i + 1];

			road_sum = 0;
		}
	}

	if(road_sum != 0)
		answer += road_sum * min_cost;


	return answer;
}

int main()
{
	int n;
	cin >> n;
	vector<int> cities;
	vector<int> roads;

	for (int i = 0; i < n - 1; i++)
	{
		int temp;
		cin >> temp;

		roads.push_back(temp);
	}

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		cities.push_back(temp);
	}

	cout << solution(cities, roads);
}