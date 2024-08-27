#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, jimin, hansu;
    cin >> N >> jimin >> hansu;

    for (int t = 1; t <= N; t++)
    {
        if (jimin == hansu + 1 && (hansu % 2 == 1 && jimin % 2 == 0))
        {
            cout << t;
            return 0;
        } 
        else if (hansu == jimin + 1 && (jimin % 2 == 1 && hansu % 2 == 0))
        {
            cout << t;
            return 0;
        }

        if (jimin % 2 == 0) jimin /= 2;
        else jimin = (jimin + 1) / 2;

        if (hansu % 2 == 0) hansu /= 2;
        else hansu = (hansu + 1) / 2;
    }

    cout << -1;
}