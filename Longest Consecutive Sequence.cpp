// https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int i, n=nums.size();
        if(n<=1) return n;
        unordered_set<int> s(nums.begin(), nums.end());
        int len=0, mx=0;
        for(i=0;i<n;i++){
            if(s.find(nums[i]-1)==s.end()){
                int temp=nums[i];
                len=1;
                while(s.find(temp+1)!=s.end()){
                    len++;
                    temp++;
                }
                mx=max(mx, len);
            }
        }
        return mx;
    }
};