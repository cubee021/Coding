#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    int zero = 0;
    int correct = 0;
    
    for(int l : lottos)
    {
        if(l == 0)
            zero++;
        else if(find(win_nums.begin(), win_nums.end(), l) != win_nums.end())
            correct++;
    }
    
    int max = correct+zero != 0 ? 7-(correct+zero) : 6;
    int min = correct != 0 ? 7-correct : 6;
    
    return vector<int>{max, min};
}