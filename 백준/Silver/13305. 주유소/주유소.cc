#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> cities, vector<int> roads)
{
	int answer = 0;
	int min = cities[0];
	int road_sum = 0;

	for (int i = 0; i < cities.size() - 1; i++)
	{
		if (cities[i] > cities[i + 1])
		{
			answer += (road_sum + roads[i]) * min;

			min = 0;
			road_sum = 0;
		}
		else
		{
			min = cities[i];
			road_sum += roads[i];
		}
	}

	if(road_sum != 0)
		answer += road_sum * min;

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