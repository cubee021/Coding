#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> board(n, vector<int>(m, 1));
    
    for(auto puddle : puddles)
    {
        int x = puddle[1] - 1;
        int y = puddle[0] - 1;
        
        board[x][y] = -1;
    }
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(board[i][j] == -1) continue;
            if(i == 0 && j == 0) continue;
            
            if(i == 0)
            {
                board[i][j] = board[i][j-1];
                continue;
            }
            else if(j == 0)
            {
                board[i][j] = board[i-1][j];
                continue;
            }
            
            int up = board[i-1][j];
            int left = board[i][j-1];
            
            if(up == -1) up = 0;
            if(left == -1) left = 0;
            
            board[i][j] = (up + left) % 1000000007;
        }
    }
    
    return board[n-1][m-1];
}