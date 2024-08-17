#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        int x1, y1, d1;
        int x2, y2, d2;

        cin >> x1 >> y1 >> d1 >> x2 >> y2 >> d2;

        float a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        float sub = abs(d1 - d2);

        if (a == 0 && d1 == d2)
            cout << -1 << '\n';
        else if (d1 + d2 == a || sub == a)
            cout << 1 << '\n';
        else if (sub < a && a < (d1 + d2))
            cout << 2 << '\n';
        else
            cout << 0 << '\n';
        
    }
}