// https://leetcode.com/problems/jump-game-ii/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return 0;
        if(nums[0]==0) return -1;
        int mx, steps, jumps;
        mx=nums[0]; steps=nums[0]; jumps=1;
        for(int i=1;i<n;i++){
            if(i==n-1) return jumps;
            mx=max(mx, nums[i]+i);
            steps--;
            if(steps==0){
                jumps++;
                if(i>=mx) return -1;
                steps=mx-i;
            }
        }
        return -1;
    }
};