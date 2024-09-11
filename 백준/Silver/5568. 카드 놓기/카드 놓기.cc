#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <string>
using namespace std;

unordered_set<int> answers;

void get_possible(vector<string>& pick)
{
	sort(pick.begin(), pick.end());

	do
	{
		string answer = "";
		for (int i = 0; i < pick.size(); i++)
			answer += pick[i];

		answers.insert(stoi(answer));
		
	} while (next_permutation(pick.begin(), pick.end()));
}

int main()
{
	int n, k;
	cin >> n >> k;
	
	vector<string> cards(n);
	for (int i = 0; i < n; i++)
		cin >> cards[i];

	vector<int> check(n, 1);
	for (int i = 0; i < k; i++)
		check[i] = 0;

	do {

		vector<string> pick;
		for (int i = 0; i < n; i++)
			if (check[i] == 0)
			{
				pick.push_back(cards[i]);
			}

		get_possible(pick);

	} while (next_permutation(check.begin(), check.end()));

	cout << answers.size();
}