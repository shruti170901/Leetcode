// https://leetcode.com/problems/hamming-distance/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int t=x^y, ans=0;
        while(t){
            ans+=t&1;
            t>>=1;
        }
        return ans;
    }
};