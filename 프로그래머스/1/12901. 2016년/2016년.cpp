#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    vector<int> months{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31};
    vector<string> days{"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};
    int temp = 0;
    
    for(int i=0; i<a-1; i++)
        temp += months[i];
    temp += b;
    
    answer = days[temp%7];
    
    return answer;
}