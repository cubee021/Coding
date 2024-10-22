#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int htom(string& h, string& m)
{
    return stoi(h)*60 + stoi(m);
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    vector<bool> started(1001, false);
    
    sort(book_time.begin(), book_time.end());
    
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                    greater<pair<int, int>>> pq; // time, work_num
    for(int i=0; i<book_time.size(); i++)
    {
        string sh = book_time[i][0].substr(0, 2);
        string sm = book_time[i][0].substr(3, 2);
        
        string eh = book_time[i][1].substr(0, 2);
        string em = book_time[i][1].substr(3, 2);
        
        pq.push({htom(sh, sm), i});
        pq.push({htom(eh, em)+10, i});
    }
    
    int key = 0;
    while(!pq.empty())
    {
        int num = pq.top().second;
        pq.pop();
        
        if(!started[num])
        {
            started[num] = true;
            answer = max(answer, ++key);
        }
        else
        {
            started[num] = false;
            key--;
        }
    }
    
    return answer;
}