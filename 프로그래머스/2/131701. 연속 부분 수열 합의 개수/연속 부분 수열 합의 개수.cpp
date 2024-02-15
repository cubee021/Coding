#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> elements) {
    set<int> answers;
    
    for(int i=1; i<=elements.size(); i++) // 추출할 길이
    {
        int sum = 0;
        
        for(int j=0; j<elements.size(); j++)
        {
            for(int k=0; k<i; k++)
                sum += elements[(j+k)%elements.size()];
            
            answers.insert(sum);
            sum = 0;
        }
    }
    
    return answers.size();
}