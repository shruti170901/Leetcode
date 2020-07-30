class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        set<int> dry;
        vector<int> res(rains.size());
        unordered_map<int, int> lakes;
        for (int i = 0; i < rains.size(); i++) {
            if (rains[i] == 0) dry.insert(i);
            else {
                int l = rains[i];
                if (lakes.count(l)) {
                    auto it = dry.upper_bound(lakes[l]);
                    if (it == dry.end()) return vector<int>();
                    res[*it] = l;
                    dry.erase(it);
                }
                lakes[l] = i;
                res[i] = -1;
            }
        }
        for (int l : dry) res[l] = 1;
        return res;
    }
};
