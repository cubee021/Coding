#include <string>
#include <algorithm>
using namespace std;

int solution(string str1, string str2) {
    int both = 0;
    int total = 0;
    pair<int, int> length = {0, 0};
    
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    
    for(int i=0; i<str2.length()-1; i++)
        if(i<str2.length()-1 && isalpha(str2[i]) && isalpha(str2[i+1]))
            length.second++;
    
    for(int i=0; i<str1.length()-1; i++)
    {
        string temp = "";
        
        if(i<str1.length()-1 && isalpha(str1[i]) && isalpha(str1[i+1]))
        {
            length.first++;
            temp += str1[i];
            temp += str1[i+1];
            
            if(str2.find(temp) != string::npos)
            {
                both++;
                string rep(1, str2[str2.find(temp)]);
                rep += "*";
                rep += str2[str2.find(temp)+1];
                str2.replace(str2.find(temp), 2, rep);
            }
        }
    }
    
    total = length.first + length.second - both;
    
    return both==0&&total==0 ? 65536 : (both/(total*1.0)) * 65536;
}