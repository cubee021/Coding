#include <string>
#include <vector>

using namespace std;

int solution(int slice, int n) {
    
    return n%slice < slice && n%slice != 0 ? n/slice+1 : n/slice;
}