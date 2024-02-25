#include<vector>
#include<queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<bool>> check(maps.size(), vector<bool>(maps[0].size()));
    vector<vector<int>> dist(maps.size(), vector<int>(maps[0].size()));
    queue<pair<int ,int>> q;

    q.push({0, 0});
    check[0][0] = true; // 예약
    dist[0][0] = 1; // 출발지의 거리는 1

    while (!q.empty()) {
        /* 방문 */
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        /* 예약 */
        for (int i = 0; i < 4; ++i) 
        {
            int nx = x + d[i][0];
            int ny = y + d[i][1];

            if(nx>=0 && nx<maps.size() && ny>=0 && ny<maps[0].size())
                if(maps[nx][ny] == 1 && !check[nx][ny])
                {
                    q.push({nx, ny});
                    check[nx][ny] = true;
                    dist[nx][ny] = dist[x][y] + 1;
                }
        }
    }
        
    // 도착지가 한번도 큐에 들어갔던적이 없다면 애초에 갈 수 없었던 곳이니 -1 리턴
    return !check[maps.size()-1][maps[0].size()-1] ? -1 :
        dist[maps.size()-1][maps[0].size()-1];
    
}