#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define INF 10000

int N, answer = 0;
int dist[50][50];

void floyd_warshall()
{
	//거쳐가는 노드
	for(int i=0; i<N; i++)
		//출발점
		for(int j=0; j<N; j++)
			//도착점
			for (int k = 0; k < N; k++)
			{
				if (dist[j][i] != INF && dist[i][k] != INF && j != k)
					dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
			}
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
		{
			dist[i][j] = INF;
		}

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;

		for (int j = 0; j < s.length(); j++)
			if(s[j] == 'Y') dist[i][j] = 1;
	}

	floyd_warshall();

	for (int i = 0; i < N; i++)
	{
		int cnt = 0;

		for (int j = 0; j < N; j++)
			if (dist[i][j] <= 2) cnt++;

		answer = max(answer, cnt);
	}

	cout << answer;
}