// https://leetcode.com/problems/unique-paths/

class Solution {
public:
    long long ncr(int N, int R){
        long long i, ans=1, n=N, r=R;
        for(i=0;i<r;i++){
            ans*=(n-i);
            ans/=(i+1);
        }
        return ans;
    }
    int uniquePaths(int m, int n) {
        return ncr(m+n-2, min(m-1, n-1));
    }
};