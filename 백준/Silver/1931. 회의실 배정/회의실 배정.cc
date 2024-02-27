#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int value[10];

int solution(vector<pair<int, int>> meetings)
{
    int answer = 1;
    
    sort(meetings.begin(), meetings.end());
	
	int time = meetings[0].first;
	for (int i = 1 ;i < meetings.size(); i++) 
	{
		if (time <= meetings[i].second )
		{
			answer++;
			time = meetings[i].first;
		}
	}

    return answer;
}

int main()
{
    vector<pair<int, int>> meetings;
	int N;

	cin >> N ;

	for (int i = 0; i < N; i++)
	{
        int begin, end;
		cin >> begin >> end;
		meetings.push_back(make_pair(end, begin));
	}
	
	cout << solution(meetings);
}