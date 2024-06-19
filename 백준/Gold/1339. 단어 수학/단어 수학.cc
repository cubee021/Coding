#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char alpha[256];

int calc(vector<string>& words, vector<char>& letters, vector<int>& num)
{
	int sum = 0;

	for (int i = 0; i < letters.size(); i++)
		alpha[letters[i]] = num[i];

	for (string s : words)
	{
		int temp = 0;
		for (char x : s)
		{
			temp = temp * 10 + alpha[x];
		}

		sum += temp;
	}

	return sum;
}

int main()
{
	int N, answer = 0;
	cin >> N;

	vector<string> words;
	vector<char> letters;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;

		words.push_back(s);

		for (char x : s) letters.push_back(x);
	}

	sort(letters.begin(), letters.end());
	letters.erase(unique(letters.begin(), letters.end()), letters.end());

	vector<int> num;
	for (int i = 0; i<letters.size(); i++)
		num.push_back(9-i);

	sort(num.begin(), num.end());

	do {

		answer = max(answer, calc(words, letters, num));

	} while (next_permutation(num.begin(), num.end()));

	cout << answer;
}