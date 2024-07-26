#include <string>
#include <vector>
using namespace std;

int answer = 0;
bool check[11][11][11][11];

vector<pair<int, int>> dh = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void set_next(pair<int, int>& cur, int n)
{
    int x = cur.first;
    int y = cur.second;
    
    int nx = x + dh[n].first;
    int ny = y + dh[n].second;
            
    if(nx>=0 && nx<=10 && ny>=0 && ny<=10)
    {
        if(!check[x][y][nx][ny])
        {
            check[x][y][nx][ny] = true;
            check[nx][ny][x][y] = true;
            answer++;
        }
        
        cur = {nx, ny};
    }
}

int solution(string dirs) {
    pair<int, int> cur = {5, 5};
    check[5][5][5][5] = true;
    
    for(char c : dirs)
    {
        if(c == 'U') set_next(cur, 0);
        else if(c == 'D') set_next(cur, 1);
        else if(c == 'L') set_next(cur, 2);
        else set_next(cur, 3);
    }
    
    return answer;
}