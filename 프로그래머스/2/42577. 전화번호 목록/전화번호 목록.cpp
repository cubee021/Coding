#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

bool solution(vector<string> phone_book) {
    set<string> s;
    
    sort(phone_book.begin(), phone_book.end());
    for(string p : phone_book)
        s.insert(p);
    
    for(string p : phone_book)
    {
        for(int i=1; i<p.length(); i++)
        {
            string temp = p.substr(0, i);
            if(s.find(temp) != s.end())
                return false;
        }
    }
    return true;
}