// https://leetcode.com/problems/power-of-four/

class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num<=0) return false;
        double l=log2(num);
        return ceil(l)==floor(l) && (int(l))%2==0;
    }
};