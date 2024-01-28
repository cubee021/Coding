#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int comp1(pair<string, int> a, pair<string, int> b)
{
    return a.second > b.second;
}

int comp2(pair<int, int> a, pair<int, int> b)
{
    if(a.first > b.first)
        return 1;
    else if(a.first == b.first)
        if(a.second < b.second)
            return 1;
    
    return 0;
    
    //return a.first > b.first ? a.second >= b.second : 0;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> m_plays_sum;
    vector<pair<string, int>> v_plays_sum;
    map<string, vector<pair<int, int>>> map; // genres, plays, idx
    
    for(int i=0; i<genres.size(); i++)
    {
        if(m_plays_sum.find(genres[i]) != m_plays_sum.end())
            m_plays_sum[genres[i]] += plays[i];
        else
            m_plays_sum[genres[i]] = plays[i];
        
        map[genres[i]].push_back({plays[i], i});
    }
    
    v_plays_sum.assign(m_plays_sum.begin(), m_plays_sum.end());
    sort(v_plays_sum.begin(), v_plays_sum.end(), comp1);
    
    for(auto& m : map)
        sort(m.second.begin(), m.second.end(), comp2);
    
    for(int i=0; i<v_plays_sum.size(); i++)
    {
        string genre = v_plays_sum[i].first;
        for(int j=0; j<map[genre].size() && j<2; j++)
            answer.push_back(map[genre][j].second);
    }
    
    return answer;
}