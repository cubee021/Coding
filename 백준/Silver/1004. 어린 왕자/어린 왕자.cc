#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>
using namespace std;

struct galaxy
{
	pair<int, int> pos;
	int r;
};

int main()
{
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		pair<int, int> start;
		pair<int, int> end;

		cin >> start.first >> start.second >> end.first >> end.second;

		int N;
		cin >> N;

		vector<galaxy> galaxyInfo;

		for (int n = 0; n < N; n++)
		{
			pair<int, int> posTemp;
			int rtemp;

			cin >> posTemp.first >> posTemp.second >> rtemp;

			galaxyInfo.push_back({ posTemp, rtemp });
		}

		// 시작, 끝점이 얼마나 많은 행성계 안에 있는지 알면 됨
		unordered_set<int> answer;

		for (int i=0; i<galaxyInfo.size(); i++)
		{
			int dx = galaxyInfo[i].pos.first - start.first;
			int dy = galaxyInfo[i].pos.second - start.second;

			int dist = sqrt(pow(dx, 2) + pow(dy, 2));

			if (dist < galaxyInfo[i].r) answer.insert(i);
		}

		for (int i = 0; i < galaxyInfo.size(); i++)
		{
			int dx = galaxyInfo[i].pos.first - end.first;
			int dy = galaxyInfo[i].pos.second - end.second;

			int dist = sqrt(pow(dx, 2) + pow(dy, 2));

			if (dist < galaxyInfo[i].r)
			{
				if (answer.find(i) == answer.end())
					answer.insert(i);
				else
					answer.erase(i);
			}
		}

		cout << answer.size() << '\n';
	}
}