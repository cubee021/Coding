#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char, int> survey_sum{{'R', 0}, {'T', 0}, {'C', 0}, {'F', 0}, 
                                   {'J', 0}, {'M', 0}, {'A', 0}, {'N', 0}};
    map<int, int> choices_list{{1, 3}, {2, 2}, {3, 1}, {4, 0}, 
                              {5, 1}, {6, 2}, {7, 3}};
    
    for(int i=0; i<survey.size(); i++)
    {
        if(choices[i] < 4)
        {
            survey_sum[survey[i][0]] += choices_list[choices[i]];
        }
        else if(choices[i] > 4)
        {
            survey_sum[survey[i][1]] += choices_list[choices[i]];
        }
    }
    
    survey_sum['R'] >= survey_sum['T'] ? answer += 'R' : answer += 'T';
    survey_sum['C'] >= survey_sum['F'] ? answer += 'C' : answer += 'F';
    survey_sum['J'] >= survey_sum['M'] ? answer += 'J' : answer += 'M';
    survey_sum['A'] >= survey_sum['N'] ? answer += 'A' : answer += 'N';
        
    return answer;
}