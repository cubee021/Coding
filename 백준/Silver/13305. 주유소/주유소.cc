#include <iostream>
#include <vector>
using namespace std;

long long solution(vector<long long> cities, vector<long long> roads)
{
	long long answer = 0;
	long long min_cost = cities[0];
	long long road_sum = 0;

	for (long long i = 0; i < cities.size() - 1; i++)
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
	vector<long long> cities;
	vector<long long> roads;

	for (int i = 0; i < n - 1; i++)
	{
		long long temp;
		cin >> temp;

		roads.push_back(temp);
	}

	for (int i = 0; i < n; i++)
	{
		long long temp;
		cin >> temp;

		cities.push_back(temp);
	}

	cout << solution(cities, roads);
}