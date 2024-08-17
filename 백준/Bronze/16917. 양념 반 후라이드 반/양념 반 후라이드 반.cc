#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;

    sum1 = X * A + Y * B;
    sum2 = C * 2 * max(X, Y);
    sum3 = C * 2 * min(X, Y);

    if (X > Y) sum3 += A * (X - Y);
    else if (X < Y) sum3 += B * (Y - X);

    cout << min(sum1, min(sum2, sum3));
}