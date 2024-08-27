#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    for (int x = -999; x <= 999; x++)
        for (int y = -999; y <= 999; y++)
        {
            int sum1 = a * x + b * y;
            int sum2 = d * x + e * y;

            if (sum1 == c && sum2 == f)
            {
                cout << x << ' ' << y;
                return 0;
            }
        }
    
}