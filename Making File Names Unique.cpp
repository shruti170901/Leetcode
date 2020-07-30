class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> map;
        vector<string> ans;
        for (auto& s : names) {
            string t = s;
            if (map.count(s)) {
                int k = ++map[s];
                t = s + "(" + to_string(k) + ")";
                while (map.count(t)) {
                    k = ++map[s];
                    t = s + "(" + to_string(k) + ")";
                }
            }
            ans.push_back(t);
            map[t] = 0;
        }
        return ans;
    }
};
