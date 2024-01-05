#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string stars = "";
    for(int i=0; i<phone_number.length() - 4; i++)
        stars += '*';
        
    phone_number.replace(phone_number.begin(), phone_number.end()-4, stars);
    
    return phone_number;
}