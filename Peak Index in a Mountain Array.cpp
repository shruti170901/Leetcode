// https://leetcode.com/problems/peak-index-in-a-mountain-array/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int i=0;
        while(i<A.size() && A[i]<A[i+1]) i++;
        return i;
    }
};