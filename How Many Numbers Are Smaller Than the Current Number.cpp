// https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans, temp;
        for(auto it:nums) temp.push_back(it);
        sort(temp.begin(), temp.end());
        for(auto it:nums){
            ans.push_back(lower_bound(temp.begin(), temp.end(), it)-temp.begin());
        }
        return ans;
        
    }
};