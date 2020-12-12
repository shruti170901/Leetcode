// https://leetcode.com/problems/sqrtx/

class Solution {
public:
    int mySqrt(int X) {
        if(X<=1) return X;
        long long l=1, r=X, mid, x=X;
        while(l<=r){
            mid=l+(r-l)/2;
            if(mid*mid<=x && ((mid+1)*(mid+1))>x) return mid;
            else if(mid*mid>x) r=mid-1;
            else l=mid+1;
        }
        return -1;
    }
};