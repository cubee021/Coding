#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n, vector<int>(n, 0));
    int num = 1;
    int x_begin = 0; int x_end = n-1;
    int y_begin = 0; int y_end = n-1;
    
    while(num <= n*n)
    {
        for(int j=y_begin; j<=y_end; j++)
            answer[x_begin][j] = num++;
        x_begin++;
        
        for(int j=x_begin; j<=x_end; j++)
            answer[j][y_end] = num++;
        y_end--;
    
        for(int j=y_end; j>=y_begin; j--)
            answer[x_end][j] = num++;
        x_end--;
        
        for(int j=x_end; j>=x_begin; j--)
            answer[j][y_begin] = num++;
        y_begin++;
    }
    
    return answer;
}