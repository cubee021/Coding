#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int H, W, N;
    cin >> H >> W >> N;

    vector<pair<int, int>> stickers(N*2);
    for (int i=0; i<N; i++)
    {
        int r, c;
        cin >> r >> c;

        stickers[i].first = r;
        stickers[i].second = c;

        stickers[i + N].first = c;
        stickers[i + N].second = r;
    }

    int max_ = 0;
    for (int i = 0; i < N*2; i++)
        for (int j = 0; j < N*2; j++)
        {
            if (i%N != j%N)
            {
                int r1 = stickers[i].first;
                int c1 = stickers[i].second;

                int r2 = stickers[j].first;
                int c2 = stickers[j].second;

                int temp = r1 * c1 + r2 * c2;

                if ((r1+r2<=H && max(c1, c2) <= W) || (c1+c2<=W && max(r1, r2) <= H))
                {
                    max_ = max(max_, temp);
                }
            }
        }
    
    cout << max_;
}