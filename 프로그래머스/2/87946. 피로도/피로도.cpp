#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    vector<int> answers;
    
    sort(dungeons.begin(), dungeons.end());
    
    do{
        int temp = k;
        int answer = 0;
        
        for(auto dungeon : dungeons)
        {   
            if(temp >= dungeon[0])
            {
                temp -= dungeon[1];
                answer++;
            }
            else
                break;
        }
        
        answers.push_back(answer);
        
    }while(next_permutation(dungeons.begin(), dungeons.end()));
    
    return *max_element(answers.begin(), answers.end());
}