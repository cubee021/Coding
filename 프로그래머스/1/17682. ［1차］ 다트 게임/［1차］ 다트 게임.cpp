#include <string>
#include <vector>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int turn = 0;
    string temp = "";
    vector<int> points(3, 0);
    
    for(char c : dartResult)
    {
        if(isdigit(c))
        {
            if(temp == "-1")
            {
                temp = "";
                turn++;
            }
            
            temp += c;
        }
        else if(isalpha(c))
        {
            if(c == 'S')
                points[turn] = stoi(temp);
            else if(c == 'D')
                points[turn] = stoi(temp) * stoi(temp);
            else if(c == 'T')
                points[turn] = stoi(temp) * stoi(temp) * stoi(temp);
            
            temp = "-1";
        }
        else 
        {
            if(c == '*')
            {
                points[turn] *= 2;
                if(turn != 0)
                    points[turn-1] *= 2;
            }
            else if(c == '#')
                points[turn] *= -1;
        }
    }
    
    for(int p : points)
        answer += p;
    
    return answer;
}