#include <string>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int answer = -1;
vector<pair<int, int>> dh = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void BFS(vector<string>& board, pair<int, int>& start, pair<int, int>& end)
{
    vector<vector<int>> dist(n, vector<int>(m, -1));
    
    queue<pair<int, int>> q;
    q.push(start);
    dist[start.first][start.second] = 0;
    
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        if(x == end.first && y == end.second)
        {
            answer = dist[x][y];
            return;
        }

        for(auto d : dh)
        {
            int nx = x + d.first;
            int ny = y + d.second;
            
            while(nx>=0 && nx<n && ny>=0 && ny<m)
            {
                if(board[nx][ny] == 'D') break;
                
                nx += d.first;
                ny += d.second;
            }
            
            if(dist[nx-d.first][ny-d.second] == -1)
            {
                q.push({nx-d.first, ny-d.second});
                dist[nx-d.first][ny-d.second] = dist[x][y] + 1;
            }
        }
    }
}

int solution(vector<string> board) {
    
    n = board.size();
    m = board[0].length();
    
    pair<int, int> start, end;
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(board[i][j] == 'R') start = {i, j};
            else if(board[i][j] == 'G') end = {i, j};
    
    BFS(board, start, end);
    
    return answer;
}