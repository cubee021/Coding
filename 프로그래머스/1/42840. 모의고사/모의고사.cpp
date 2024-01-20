#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> s1{1, 2, 3, 4, 5};
    vector<int> s2{2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> s3{3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    vector<int> counts(3, 0);
    
    for(int i=0; i<answers.size(); i++)
    {
        if(s1[i%s1.size()] == answers[i]) counts[0]++;
        if(s2[i%s2.size()] == answers[i]) counts[1]++;
        if(s3[i%s3.size()] == answers[i]) counts[2]++;
    }
    
    int max = *max_element(counts.begin(), counts.end());
    for(int i=0; i<counts.size(); i++)
    {
        if(counts[i] == max) answer.push_back(i+1);
    }
    
    return answer;
}