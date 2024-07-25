#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    unordered_map<int, int> map1;
    unordered_map<int, int> map2;
    
    for(int i : topping) map2[i]++;
    
    for(int i : topping)
    {
        map1[i]++;
        map2[i]--;
        if(map2[i] == 0) map2.erase(i);
        
        if(map1.size() == map2.size()) answer++;
        else if(map1.size() > map2.size()) break;
    }
    
    return answer;
}