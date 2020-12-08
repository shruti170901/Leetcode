// https://leetcode.com/problems/permutations-ii/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        do{
            temp=nums;
            ans.push_back(temp);
        }while(next_permutation(nums.begin(), nums.end()));
        return ans;
    }
};