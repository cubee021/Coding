#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

int N, M;
pair<int, int> S, E;

vector<pair<int, int>> dh = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int dist[100][100][2];

int BFS(vector<string>& maps)
{
    queue<tuple<int, int, int>> q; // x, y, lever
    
    q.push({S.first, S.second, 0});
    dist[S.first][S.second][0] = 0;
    
    while(!q.empty())
    {
        int x, y, l;
        tie(x, y, l) = q.front();
        q.pop();
        
        if(x == E.first && y == E.second && l == 1)
            return dist[x][y][l];
        
        for(auto h : dh)
        {
            int nx = x + h.first;
            int ny = y + h.second;
            int nl = l;
            
            if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
            
            if(maps[nx][ny] == 'X') continue;
            else if(maps[nx][ny] == 'L') nl = 1;
            
            if(dist[nx][ny][nl] == -1)
            {
                dist[nx][ny][nl] = dist[x][y][l] + 1;
                q.push({nx, ny, nl});
            }
        }
    }
    
    return -1;
}

int solution(vector<string> maps) {
    N = maps.size();
    M = maps[0].length();
    
    memset(dist, -1, sizeof(dist));
    
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            if(maps[i][j] == 'S')
                S = {i, j};
            else if(maps[i][j] == 'E')
                E = {i, j};
    
    return BFS(maps);
}