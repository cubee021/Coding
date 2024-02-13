#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    int S_xpos = 0;
    int S_ypos = 0;
    
    //처음 S의 위치
    for(int i=0; i<park.size(); i++)
    {
        if(park[i].find("S") != string::npos)
        {
            S_xpos = i;
            S_ypos = park[i].find("S");
        }
    }
    
    for(string route : routes)
    {
        pair<int, int> dir;
        int length = route[2] - '0';
        
        if(route[0] == 'E')
            dir = {0, 1};
        else if(route[0] == 'W')
            dir = {0, -1};
        else if(route[0] == 'S')
            dir = {1, 0};
        else if(route[0] == 'N')
            dir = {-1, 0};
        
        pair<int, int> temp = {S_xpos, S_ypos};
        int i;
        for(i=0; i<length; i++)
        {
            temp.first += dir.first;
            temp.second += dir.second;
            
            if(temp.first<0 || temp.first>=park.size() || 
               temp.second<0 || temp.second>=park[0].length())
                break;
            
            if(park[temp.first][temp.second] == 'X')
                break;
        }
        
        if(i == length)
        {
            S_xpos = temp.first;
            S_ypos = temp.second;
        }
    }
    
    return {S_xpos, S_ypos};
}