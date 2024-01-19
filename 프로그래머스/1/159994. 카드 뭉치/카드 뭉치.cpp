#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    int c1_idx = 0;
    int c2_idx = 0;
    
    for(string s : goal)
    {
        if(cards1[c1_idx] == s)
            c1_idx++;
        else if(cards2[c2_idx] == s)
            c2_idx++;
        else
            return "No";
    }
    
    return "Yes";
}