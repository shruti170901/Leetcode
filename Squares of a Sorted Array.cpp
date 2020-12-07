// https://leetcode.com/problems/squares-of-a-sorted-array/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> ans;
        for(auto it:A) ans.push_back(it*it);
        sort(ans.begin(), ans.end());
        return ans;
    }
};