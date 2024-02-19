#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string new_id) {
    string answer = "";
    
    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower); // 1
    
    for(char c : new_id) // 2
        if(isalpha(c) || isdigit(c) || c=='-' || c=='_' || c=='.')
            answer += c;
    
    while(true) // 3
    {
        if(answer.find("..") != string::npos)
            answer.replace(answer.find(".."), 2, ".");
        else
            break;
    }
    
    if(answer.front() == '.') answer.erase(answer.begin()); // 4
    if(answer.back() == '.') answer.pop_back();
    
    if(answer.empty()) answer += "a"; // 5
    
    if(answer.length() > 15) // 6
    {
        answer.assign(answer.begin(), answer.begin()+15);
        if(answer.back() == '.') answer.pop_back();
    }
    
    while(answer.length() <= 2) // 7
        answer += answer[answer.length()-1];
    
    return answer;
}