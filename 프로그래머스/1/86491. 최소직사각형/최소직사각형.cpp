#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int longest_W = 0; // 가로
    int longest_H = 0; // 세로
    
    for(auto& size : sizes)
    {
        if(size[0] < size[1])
        {
            int temp = size[0];
            size[0] = size[1];
            size[1] = temp;
        }
        
        if(longest_W < size[0])
            longest_W = size[0];
        
        if(longest_H < size[1])
            longest_H = size[1];
    }
    
    return longest_W * longest_H;
}