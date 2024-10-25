#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int area[100][100];

vector<pair<int, int>> dh = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void BFS(vector<string>& maps, int i, int j, int num)
{
    queue<pair<int, int>> q;
    
    q.push({i, j});
    area[i][j] = num;
    
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(auto h : dh)
        {
            int nx = x + h.first;
            int ny = y + h.second;
            
            if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
            if(maps[nx][ny] == 'X') continue;
            if(area[nx][ny] == -1)
            {
                area[nx][ny] = num;
                q.push({nx, ny});
            }
        }
    }
}

vector<int> solution(vector<string> maps) {
    N = maps.size();
    M = maps[0].size();
    
    memset(area, -1, sizeof(area));
    
    int num = 0;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            if(area[i][j] == -1 && maps[i][j] != 'X')
            {
                BFS(maps, i, j, num);
                num++;
            }
    
    vector<int> answer(num, 0);
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
        {
            if(area[i][j] != -1)
                answer[area[i][j]] += (maps[i][j]-'0');
        }
    
    if(answer.empty()) return {-1};
    sort(answer.begin(), answer.end());
    
    return answer;
}