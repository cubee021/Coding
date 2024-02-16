#include <string>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int> cars;
    map<string, int> temp;
    
    for(string s : records)
    {
        string car_num = s.substr(6, 4);
        int current_time = stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
        
        if(s.length() == 13) // IN
        {
            temp[car_num] = current_time;
        }
        else // OUT
        {
            int mins = current_time - temp.find(car_num)->second;
            
            if(cars.find(car_num) != cars.end())
                cars[car_num] += mins;
            else
                cars[car_num] = mins;
            
            temp.erase(temp.find(car_num));
        }
    }
    
    for(auto iter=temp.begin(); iter!=temp.end(); iter++)
    {
        int mins = 1439 - iter->second;
            
        if(cars.find(iter->first) != cars.end())
            cars[iter->first] += mins;
        else
            cars[iter->first] = mins;
    }
    
    for(auto iter=cars.begin(); iter!=cars.end(); iter++)
    {
        int total = fees[1];
        
        if(iter->second > fees[0])
            total += ceil((iter->second-fees[0])/(fees[2]*1.0)) * fees[3];
        
        answer.push_back(total);
    }
    
    return answer;
}