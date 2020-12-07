// https://leetcode.com/problems/unique-number-of-occurrences/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        unordered_set<int> s;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }
        for(auto it:m) s.insert(it.second);
        return m.size()==s.size();
    }
};