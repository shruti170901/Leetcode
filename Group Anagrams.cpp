// https://leetcode.com/problems/group-anagrams/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> m;
        string temp;
        for(string s:strs){
            temp=s;
            sort(temp.begin(), temp.end());
            m[temp].push_back(s);
        }
        for(auto it:m) ans.push_back(it.second);
        return ans;
    }
};