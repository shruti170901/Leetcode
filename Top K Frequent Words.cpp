bool cmp(const pair<int, string> a, const pair<int, string> b){
        if(a.first==b.first) return a.second<b.second;
        else return a.first>b.first;
    }

class Solution {
public:
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mp;
        for(auto word: words) mp[word]++;
        vector<pair<int, string>> vp;
        vp.reserve(words.size());
        for(auto c: mp){
            vp.push_back({c.second, c.first});
        }
        
        sort(vp.begin(), vp.end(), cmp);
        vector<string> res(k);
        for(int i=0; i<k; i++) res[i]=vp[i].second;
        return res;
    }
};