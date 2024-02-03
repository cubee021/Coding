#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 0;
    
    vector<vector<int>> d{{1, 0}, {0, 1}, {-1, 0}, {0, -1}, 
                          {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
    
    for(int x=0; x<board.size(); x++)
        for(int y=0; y<board.size(); y++)
        {
            if(board[x][y] == 1)
            {
                for(int i=0; i<8; i++)
                {
                    int nx = x + d[i][0];
                    int ny = y + d[i][1];
                    
                    if((nx >= 0 && nx<board.size())&&(ny >= 0 && ny<board.size()))
                        if(board[nx][ny] != 1)
                            board[nx][ny] = 2;
                }
            }
        }
    
    for(int x=0; x<board.size(); x++)
        for(int y=0; y<board.size(); y++)
            if(board[x][y] == 0)
                answer++;
    
    return answer;
}