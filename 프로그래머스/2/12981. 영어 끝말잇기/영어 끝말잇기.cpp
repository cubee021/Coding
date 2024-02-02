#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    
    vector<int> player(n, 0);
    set<string> used;
    string before = "";
    
    for(int i=0; i<words.size(); i++)
    {
        player[i%n]++;
        
        if(used.find(words[i]) != used.end())
            return vector<int>{i%n+1, player[i%n]};
        
        if(before[before.length()-1] != words[i][0] && i != 0)
            return vector<int>{i%n+1, player[i%n]};
        
        before = words[i];
        used.insert(words[i]);
    }
    
    return vector<int>{0, 0};
}