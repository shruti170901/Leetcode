// https://leetcode.com/problems/search-insert-position/

class Solution {
public:
    int searchInsert(vector<int>& nums, int t) {
        return lower_bound(nums.begin(), nums.end(), t)-nums.begin();
    }
};