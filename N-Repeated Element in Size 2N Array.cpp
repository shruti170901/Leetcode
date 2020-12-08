// https://leetcode.com/problems/n-repeated-element-in-size-2n-array/

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int i, n=A.size();
        if(n==2) return A[0];
        set<int> s;
        for(i=0;i<n;i++){
            if(s.find(A[i])==s.end()) s.insert(A[i]);
            else return A[i];
        }
        return 0;
    }
};