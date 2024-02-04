#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> stack;
    
    for(int move : moves)
    {
        int grab = 0;
        for(int i=0; i<board.size(); i++)
        {
            if(board[i][move-1] != 0)
            {
                grab = board[i][move-1];
                board[i][move-1] = 0;
                break;
            }
        }
        
        if(grab == 0) continue;
        
        if(stack.empty())
            stack.push(grab);
        else
        {
            if(stack.top() == grab)
            {
                stack.pop();
                answer += 2;
            }
            else
                stack.push(grab);
        }
    }
    
    return answer;
}