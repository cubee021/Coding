#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    for(auto& i : arr)
        answer += i * 1.0;
    return answer / arr.size();
}