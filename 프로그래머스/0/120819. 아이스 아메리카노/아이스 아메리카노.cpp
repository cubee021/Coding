#include <string>
#include <vector>

using namespace std;

vector<int> solution(int money) {
    return vector<int>{money/5500, money%5500};
}