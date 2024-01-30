#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string X, string Y) {
    string answer = "";
    
    sort(X.begin(), X.end(), greater<char>());
    sort(Y.begin(), Y.end(), greater<char>());
    
    int i=0; int j=0;
    
    while(i != X.size() || j != Y.size())
    {
        if(X[i] == Y[j])
        {
            answer.push_back(X[i]);
            i++; j++;
        }
        else
            X[i] > Y[j] ? i++ : j++;
    }
    
    if(answer.empty()) return "-1";
    
    return answer[0] != '0' ? answer : "0";
}