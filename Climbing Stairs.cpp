// https://leetcode.com/problems/climbing-stairs/

class Solution {
public:
    int climbStairs(int n) {
        if(n<=1) return 1;
        int f1=1, f2=1;
        while(n-->=2){
            f2+=f1;
            f1=f2-f1;
        }
        return f2;
    }
};