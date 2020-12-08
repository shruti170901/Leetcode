// https://leetcode.com/problems/sort-array-by-parity/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int n=A.size(), l, r;
        l=0; r=n-1;
        while(l<r){
            while(r>=0 && A[r]%2==1) r--;
            while(l<n && A[l]%2==0) l++;
            if(l<r){
                swap(A[l], A[r]);
                l++;
                r--;
            }
        }
        return A;
    }
};