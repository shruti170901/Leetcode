// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int t) {
        vector<int> ans(2, -1);
        auto it=lower_bound(nums.begin(), nums.end(), t);
        if(it==nums.end() || *it!=t) return ans;
        else ans[0]=it-nums.begin();
        ans[1]=upper_bound(nums.begin(), nums.end(), t)-nums.begin()-1;
        return ans;
    }
};