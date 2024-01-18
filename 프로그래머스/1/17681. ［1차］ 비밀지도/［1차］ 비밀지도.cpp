#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string to_binary(int length, int decimal)
{
    string binary = "";
    int i=0;
    while(i++ < length)
    {
        binary += to_string(decimal%2);
        decimal /= 2;
    }
    
    reverse(binary.begin(), binary.end());
    return binary;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i=0; i<arr1.size(); i++)
    {
        string temp = "";
        string a1 = to_binary(n, arr1[i]);
        string a2 = to_binary(n, arr2[i]);
        
        for(int j=0; j<a1.length(); j++)
            temp += (a1[j]-'0') || (a2[j]-'0') ? '#' : ' ';
        
        answer.push_back(temp);
    }
    
    return answer;
}