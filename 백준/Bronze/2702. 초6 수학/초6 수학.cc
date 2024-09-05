#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//최대공약수
int gcd(int a, int b)
{
	int r = a%b;

	while (r > 0)
	{
		a = b;
		b = r;

		r = a % b;
	}

	return b;
}

//최소공배수
int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

int main()
{
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int a, b;
		cin >> a >> b;


		cout << lcm(a, b) << ' ' << gcd(a, b) << '\n';
	}
}