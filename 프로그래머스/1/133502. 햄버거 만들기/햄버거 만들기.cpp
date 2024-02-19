#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> v{-1};

    for(int i : ingredient)
    {
        if(i==2 && v.back()==1) v.back() = 12;
        else if(i==3 && v.back()==12) v.back() = 123;
        else if(i==1 && v.back()==123) 
        {
            v.pop_back();
            answer++;
        }
        else v.push_back(i);
    }
    
    return answer;
}