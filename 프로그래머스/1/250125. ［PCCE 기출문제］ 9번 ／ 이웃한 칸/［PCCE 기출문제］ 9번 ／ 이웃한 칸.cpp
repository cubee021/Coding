#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int count = 0;
    int n = board.size();
    vector<vector<int>> d{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    for(int i=0; i<4; i++)
    {
        int h_check = h + d[i][0];
        int w_check = w + d[i][1];
        
        if(h_check>=0 && h_check<n && w_check>=0 && w_check<n)
            if(board[h][w] == board[h_check][w_check])
                count++;
    }

    return count;
}