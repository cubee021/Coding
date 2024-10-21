#include <string>
#include <vector>

using namespace std;

vector<int> count[3][2][2][2];

int get_num(string s)
{
    if(s == "cpp" || s == "backend" || s == "junior" || s == "chicken") 
        return 0;
    else if(s == "java" || s == "frontend" || s == "senior" || s == "pizza")
        return 1;
    else if(s == "python")
        return 2;

    return -1;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    //저장부
    for(string i : info)
    {
        vector<int> temp;
        string s = "";

        for(char c : i)
        {
            if(c == ' ')
            {
                temp.push_back(get_num(s));
                s = "";
            }
            else
                s += c;
        }
        temp.push_back(stoi(s));

        count[temp[0]][temp[1]][temp[2]][temp[3]].push_back(temp[4]);
    }

    //검색부
    for(string q : query)
    {
        vector<int> temp;
        string s = "";

        for(char c : q)
        {
            if(c == ' ')
            {
                if(s != "and")
                    temp.push_back(get_num(s));
                s = "";
            }
            else
                s += c;
        }
        temp.push_back(stoi(s));

        int cnt = 0;
        for(int i=0; i<3; i++)
        {
            if(temp[0] != i && temp[0] != -1) continue;
            for(int j=0; j<2; j++)
            {
                if(temp[1] != j && temp[1] != -1) continue;
                for(int k=0; k<2; k++)
                {
                    if(temp[2] != k && temp[2] != -1) continue;
                    for(int l=0; l<2; l++)
                    {
                        if(temp[3] != l && temp[3] != -1) continue;

                        for(auto score : count[i][j][k][l])
                            if(score >= temp[4]) cnt++;
                    }
                }
            }
        }

        answer.push_back(cnt);
    }


    return answer;
}