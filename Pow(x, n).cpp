// https://leetcode.com/problems/powx-n/

class Solution {
public:
    double myPow(double x, int n) {
        long long exp=n;
        if(x==0) return 0;
        if(exp==0) return 1;
        if(exp<0) x=1/x, exp*=-1;
        double ans=1, base=x;
        while(exp>0){
            if(exp&1) ans=ans*base;
            base=base*base;
            exp/=2;
        }
        return ans;
    }
};