class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gs) {
        vector<vector<int>> res;
        unordered_map<int,vector<int>> mp;
        for (int i = 0; i < gs.size(); ++i) {
            mp[gs[i]].push_back(i);
        }
        for (auto x : mp) {
             int i = x.first; 
             vector<int> v = x.second;
             vector<int> t(i);
             for (int j = 0; j < v.size(); ++j) {
                 t[j % i] = v[j];
                 if ((j + 1) % i == 0) {
                     res.push_back(t);
                 }
            }
        }
        return res;
    }
};
