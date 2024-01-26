#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    for(char& c : myString)
        c == 'A' ? c='B' : c='A';
    
    if(myString.find(pat) != string::npos)
        return 1;
    
    return 0;
}