#include <string>
#include <vector>

using namespace std;

int N;

bool check(vector<vector<int>>& arr, int x, int y, int w)
{
    int num = arr[x][y];
    
    for(int i=x; i<x+w; i++)
        for(int j=y; j<y+w; j++)
            if(num != arr[i][j]) return false;
        
    for(int i=x; i<x+w; i++)
        for(int j=y; j<y+w; j++)
            arr[i][j] = -1;
    
    return true;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer = {0, 0};
    N = arr.size();
    
    int w = N;
    while(w > 0)
    {
        for(int i=0; i<N; i += w)
            for(int j=0; j<N; j += w)
            {
                if(arr[i][j] == -1) continue;
                
                int num = arr[i][j];
                if(check(arr, i, j, w))
                {
                    answer[num]++;
                }
            }
        
        w /= 2;
    }
    
    return answer;
}