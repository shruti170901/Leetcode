// https://leetcode.com/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& A) {
        int mx, step, i, n=A.size();
        if(n<=1) return true;
        mx=A[0]; step=A[0];
        if(A[0]==0) return false;
        for(i=1;i<n;i++){
            if(i==n-1) return true;
            mx=max(mx, i+A[i]);
            step--;
            if(step==0){
                if(i>=mx) return false;
                step=mx-i;
            }
        }
        return true;
    }
};